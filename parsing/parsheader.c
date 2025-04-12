/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsheader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:18:56 by mjamil            #+#    #+#             */
/*   Updated: 2025/04/12 17:53:57 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *extract_value(char *line, char *prefix)
{
    line += ft_strlen(prefix);
    while (*line == ' ' || *line == '\t')
        line++;
    char *value = trim_line(line);

    // Remove trailing newline characters
    size_t len = ft_strlen(value);
    if (len > 0 && value[len - 1] == '\n')
        value[len - 1] = '\0';

    printf("Extracted value: '%s'\n", value);  // Debugging line
    return value;
}


int is_map_line(char *line)
{
    int i = 0;
    
    // Skip whitespace
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    
    // Check for valid map characters
    if (line[i] == '0' || line[i] == '1' || line[i] == ' ' ||
        line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
        return 1;
    
    return 0;
}



int is_empty_line(char *line)
{
    while (*line)
    {
        if (*line != ' ' && *line != '\t' && *line != '\n')  // Add check for '\n' here
            return 0;
        line++;
    }
    return 1;
}


int starts_with(char *line, const char *prefix)
{
    while (*prefix)
    {
        if (*line != *prefix)
            return 0;
        line++;
        prefix++;
    }
    return 1;
}

char *ft_strdup(const char *s)
{
    char *new_str;
    size_t len = ft_strlen(s) + 1;
    new_str = malloc(len);
    if (!new_str)
        return NULL;
    ft_memcpy(new_str, s, len);
    return new_str;
}

char *trim_line(char *line)
{
    while (*line && (*line == ' ' || *line == '\t'))
        line++;
    char *end = line + ft_strlen(line) - 1;
    while (end > line && (*end == ' ' || *end == '\t'))
        end--;
    *(end + 1) = '\0';
    return line;
}

t_color parse_color(char *line)
{
    t_color color;
    char *trimmed = trim_line(line);
    char *comma1 = strchr(trimmed, ',');
    char *comma2 = strrchr(trimmed, ',');
    
    if (!comma1 || !comma2 || comma1 == comma2)
        error_exit("Invalid color format");
    
    *comma1 = '\0';
    *comma2 = '\0';
    
    color.r = ft_atoi(trimmed);
    color.g = ft_atoi(comma1 + 1);
    color.b = ft_atoi(comma2 + 1);
    
    if (color.r < 0 || color.r > 255 || 
        color.g < 0 || color.g > 255 || 
        color.b < 0 || color.b > 255)
        error_exit("Color values must be between 0-255");
    
    return color;
}



void error_exit(const char *msg)
{
    fprintf(stderr, "Error\n%s\n", msg);
    exit(1);
}

void parse_header(t_config *config, char **lines)
{
    int i = 0;
    int textures_parsed = 0;
    int floor_parsed = 0;
    int ceiling_parsed = 0;

    while (lines[i] && !is_map_line(lines[i]))
    {
        if (is_empty_line(lines[i]))
        {
            i++;
            continue;
        }

        char *trimmed = trim_line(lines[i]);
        
        if (starts_with(trimmed, "NO") && !config->texture.north)
        {
            config->texture.north = ft_strdup(extract_value(trimmed, "NO"));
            textures_parsed++;
        }
        else if (starts_with(trimmed, "SO") && !config->texture.south)
        {
            config->texture.south = ft_strdup(extract_value(trimmed, "SO"));
            textures_parsed++;
        }
        else if (starts_with(trimmed, "WE") && !config->texture.west)
        {
            config->texture.west = ft_strdup(extract_value(trimmed, "WE"));
            textures_parsed++;
        }
        else if (starts_with(trimmed, "EA") && !config->texture.east)
        {
            config->texture.east = ft_strdup(extract_value(trimmed, "EA"));
            textures_parsed++;
        }
        else if (starts_with(trimmed, "F") && !floor_parsed)
        {
            config->floor_color = parse_color(extract_value(trimmed, "F"));
            floor_parsed = 1;
        }
        else if (starts_with(trimmed, "C") && !ceiling_parsed)
        {
            config->ceiling_color = parse_color(extract_value(trimmed, "C"));
            ceiling_parsed = 1;
        }
        else
        {
            error_exit("Duplicate or invalid configuration");
        }
        i++;
    }

    // Validation
    if (textures_parsed != 4 || !floor_parsed || !ceiling_parsed)
        error_exit("Missing configuration elements");
}


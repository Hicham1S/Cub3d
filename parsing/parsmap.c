/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:11:12 by mjamil            #+#    #+#             */
/*   Updated: 2025/04/12 17:46:17 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void validate_map(t_map *map)
{
    int player_count = 0;
    int i, j;

    // Check map is surrounded by walls
    for (i = 0; i < map->height; i++)
    {
        for (j = 0; j < map->width; j++)
        {
            // Check borders
            if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
            {
                if (map->grid[i][j] != '1' && map->grid[i][j] != ' ')
                    error_exit("Map not surrounded by walls");
            }

            // Check player position
            if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S' || 
                map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
            {
                player_count++;
                // You should set player position here
            }

            // Check valid characters
            if (map->grid[i][j] != '0' && map->grid[i][j] != '1' && 
                map->grid[i][j] != ' ' && map->grid[i][j] != 'N' && 
                map->grid[i][j] != 'S' && map->grid[i][j] != 'E' && 
                map->grid[i][j] != 'W')
            {
                error_exit("Invalid character in map");
            }
        }
    }

    if (player_count != 1)
        error_exit("Map must contain exactly one player");
}

void parse_map(t_config *scene, char **lines, int start_index)
{
    int i = start_index;
    int map_lines = 0;
    int max_width = 0;

    // First pass: count lines and find max width
    while (lines[i])
    {
        if (!is_empty_line(lines[i]))
        {
            map_lines++;
            int len = ft_strlen(lines[i]);
            if (len > max_width)
                max_width = len;
        }
        i++;
    }

    scene->map.height = map_lines;
    scene->map.width = max_width;
    scene->map.grid = malloc(sizeof(char *) * (map_lines + 1)); // +1 for NULL terminator
    if (!scene->map.grid)
        error_exit("Memory allocation error");

    // Second pass: copy and normalize lines
    i = start_index;
    int j = 0;
    while (lines[i])
    {
        if (!is_empty_line(lines[i]))
        {
            // Remove newline if present
            char *nl = strchr(lines[i], '\n');
            if (nl) *nl = '\0';
            
            // Allocate and copy line
            scene->map.grid[j] = ft_strdup(lines[i]);
            if (!scene->map.grid[j])
                error_exit("Memory allocation error for map line");

            // Normalize width by padding with spaces if needed
            if ((int)ft_strlen(scene->map.grid[j]) < scene->map.width)
            {
                char *new_line = malloc(scene->map.width + 1);
                ft_strlcpy(new_line, scene->map.grid[j], scene->map.width + 1);
                ft_memset(new_line + ft_strlen(scene->map.grid[j]), ' ', 
                          scene->map.width - ft_strlen(scene->map.grid[j]));
                new_line[scene->map.width] = '\0';
                free(scene->map.grid[j]);
                scene->map.grid[j] = new_line;
            }
            j++;
        }
        i++;
    }
    scene->map.grid[j] = NULL; // NULL-terminate the grid

    validate_map(&scene->map);
}
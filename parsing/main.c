#include "../includes/cub3d.h"

// int main(void)
// {
// 	char **lines;
// 	int i = 0;

// 	lines = read_file_line("map.txt");
// 	if (!lines)
// 	{
// 		printf("Error reading file.\n");
// 		return (1);
// 	}

// 	while (lines[i])
// 	{
// 		printf("Line %d: %s", i, lines[i]);
// 		free(lines[i]);
// 		i++;
// 	}
// 	free(lines);
// 	return 0;
// }




// gcc main.c parsing.c parsheader.c ../libft/libft.a -I../includes -o test

// int main(void)
// {
//     char **lines = read_file_line("map.txt");
//     if (!lines)
//     {
//         printf("Error reading map file.\n");
//         return (1);
//     }

//     t_config config = {0}; // Zero out config

//     parse_header(&config, lines);

//     // Output parsed values
//     printf("North: %s\n", config.texture.north);
//     printf("South: %s\n", config.texture.south);
//     printf("West: %s\n", config.texture.west);
//     printf("East: %s\n", config.texture.east);
//     printf("Floor color: R=%d, G=%d, B=%d\n",
//            config.floor_color.r, config.floor_color.g, config.floor_color.b);
//     printf("Ceiling color: R=%d, G=%d, B=%d\n",
//            config.ceiling_color.r, config.ceiling_color.g, config.ceiling_color.b);

//     // Cleanup
//     for (int i = 0; lines[i]; i++)
//         free(lines[i]);
//     free(lines);
//     free(config.texture.north);
//     free(config.texture.south);
//     free(config.texture.west);
//     free(config.texture.east);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

// Helper function to convert t_color to hex RGB
unsigned int color_to_hex(t_color color)
{
    return ((color.r & 0xff) << 16) | ((color.g & 0xff) << 8) | (color.b & 0xff);
}

int find_map_start_index(char **lines)
{
    int i = 0;
    while (lines[i])
    {
        if (!is_empty_line(lines[i]) && is_map_line(lines[i]))
            return i;
        i++;
    }
    return -1;
}

void print_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}

void free_config(t_config *config)
{
    if (config->texture.north) free(config->texture.north);
    if (config->texture.south) free(config->texture.south);
    if (config->texture.east) free(config->texture.east);
    if (config->texture.west) free(config->texture.west);
    
    if (config->map.grid)
    {
        int i = 0;
        while (config->map.grid[i])
        {
            free(config->map.grid[i]);
            i++;
        }
        free(config->map.grid);
    }
}

void free_lines(char **lines)
{
    if (lines)
    {
        int i = 0;
        while (lines[i])
        {
            free(lines[i]);
            i++;
        }
        free(lines);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file.cub>\n", argv[0]);
        return 1;
    }

    // Read lines from file
    char **lines = read_file_line(argv[1]);
    if (!lines)
    {
        fprintf(stderr, "Failed to read file.\n");
        return 1;
    }

    // Initialize config
    t_config config = {
        .texture = {NULL, NULL, NULL, NULL},
        .floor_color = {0, 0, 0},
        .ceiling_color = {0, 0, 0},
        .map = {NULL, 0, 0}
    };

    // Parse header
    parse_header(&config, lines);

    // Find map start index
    int map_start = find_map_start_index(lines);
    if (map_start == -1)
    {
        fprintf(stderr, "Error: Map start not found\n");
        free_config(&config);
        free_lines(lines);
        return 1;
    }

    // Parse map
    parse_map(&config, lines, map_start);

    // Output parsed data for validation
    printf("North Texture: %s\n", config.texture.north);
    printf("South Texture: %s\n", config.texture.south);
    printf("East Texture:  %s\n", config.texture.east);
    printf("West Texture:  %s\n", config.texture.west);
    printf("Floor Color:   #%06x\n", color_to_hex(config.floor_color));
    printf("Ceiling Color: #%06x\n", color_to_hex(config.ceiling_color));
    printf("Map (%dx%d):\n", config.map.width, config.map.height);
    print_map(config.map.grid);

    // Free memory
    free_config(&config);
    free_lines(lines);

    return 0;
}
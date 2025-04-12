/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:06:56 by mjamil            #+#    #+#             */
/*   Updated: 2025/04/12 14:16:09 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

// === Keycodes ===
# define ESC         65307
# define W           119
# define A           97
# define S           115
# define D           100
# define LEFT_ARROW  65361
# define RIGHT_ARROW 65363

// === Colors ===
# define WHITE 0xFFFFFF
# define GREY  0x808080
# define RED   0xFF0000
# define BLACK 0x000000
# define GREEN 0x00FF00

// === Structs ===

typedef struct s_color
{
	int r;
	int g;
	int b;
}	t_color;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_texture;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;


typedef struct s_config
{
	t_texture	texture;
	t_color		floor_color;
	t_color		ceiling_color;
	t_map		map;
	t_player	player;
}	t_config;

typedef struct s_player {
    double x;       // position x
    double y;       // position y
    double dir_x;   // direction vector x
    double dir_y;   // direction vector y
    double plane_x; // camera plane x (for FOV)
    double plane_y; // camera plane y
} t_player;

typedef struct s_ray {
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    int step_x;
    int step_y;
    int hit;        // was a wall hit?
    int side;       // vertical or horizontal
} t_ray;



char **read_file_line(char *file);

#endif

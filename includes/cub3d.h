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

typedef struct s_player
{
	int		x;
	int		y;
	char	direction; // N, S, E, W
}	t_player;

typedef struct s_config
{
	t_texture	texture;
	t_color		floor_color;
	t_color		ceiling_color;
	t_map		map;
	t_player	player;
}	t_config;



char **read_file_line(char *file);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:24:51 by afarachi          #+#    #+#             */
/*   Updated: 2025/05/18 18:12:13 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static bool	is_explorable(char **map, int i, int j)
{
	return (map[j][i] == '0' || is_player_spawn_pos(map[j][i]));
}

static bool	is_valid_char(char c)
{
	return (c != '0' && c != '1' && c != ' ');
}

static bool	check_neighbours(char **map, int i, int j, int map_height)
{
	int	y;
	int	x;
	int	ni;
	int	nj;

	y = -1;
	while (y <= 1)
	{
		x = -1;
		while (x <= 1)
		{
			ni = i + x;
			nj = j + y;
			if (nj < 0 || nj >= map_height || ni < 0
				|| ni >= ft_strlen1(map[nj]) || !map[nj][ni]
				|| map[nj][ni] == ' ')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

static void	check_map_closed(t_cub_data *cub_data, char **map, int map_height,
		int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map_height)
	{
		i = 0;
		while (map[j][i])
		{
			if (is_valid_char(map[j][i]) && !is_player_spawn_pos(map[j][i]))
			{
				close(fd);
				cub_exit(MAP_WRONG_CHARACTER, cub_data);
			}
			if (is_explorable(map, i, j) && !check_neighbours(map, i, j,
					map_height))
			{
				close(fd);
				cub_exit(MAP_UNCLOSED, cub_data);
			}
			i++;
		}
		j++;
	}
}

void	check_map_validity(t_cub_data *cub_data, int fd)
{
	if (!cub_data->settings.map)
	{
		close(fd);
		cub_exit(MAP_MISSING, cub_data);
	}
	check_map_closed(cub_data, cub_data->settings.map,
		double_array_len(cub_data->settings.map), fd);
}

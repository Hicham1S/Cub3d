/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_player_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:59:03 by mjamil            #+#    #+#             */
/*   Updated: 2025/05/18 20:59:05 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	check_if_player_pos(t_cub_data *cub_data, bool *set, int i, int j)
{
	if (is_player_spawn_pos(cub_data->settings.map[j][i]))
	{
		if (*set)
			cub_exit(MAP_DUPLICATED_PLAYER_SPAWN_POS, cub_data);
		cub_data->player_data.pole = cub_data->settings.map[j][i];
		if (cub_data->player_data.pole == 'N')
			cub_data->player_data.angle = 3 * M_PI / 2;
		else if (cub_data->player_data.pole == 'E')
			cub_data->player_data.angle = 0.0f;
		else if (cub_data->player_data.pole == 'S')
			cub_data->player_data.angle = M_PI / 2;
		else if (cub_data->player_data.pole == 'W')
			cub_data->player_data.angle = M_PI;
		cub_data->player_data.x = i + 0.5;
		cub_data->player_data.y = j + 0.5;
		*set = true;
	}
}

static void	get_map_height_and_width(t_cub_data *cub_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cub_data->utils.map_width = 0;
	while (cub_data->settings.map[j])
	{
		i = 0;
		while (cub_data->settings.map[j][i])
		{
			i++;
		}
		if (cub_data->utils.map_width < i)
			cub_data->utils.map_width = i;
		j++;
	}
	cub_data->utils.map_height = j;
}

void	store_player_pos(t_cub_data *cub_data)
{
	int		i;
	int		j;
	bool	set;

	i = 0;
	j = 0;
	set = false;
	get_map_height_and_width(cub_data);
	while (cub_data->settings.map[j])
	{
		while (cub_data->settings.map[j][i])
		{
			check_if_player_pos(cub_data, &set, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	if (!set)
		cub_exit(MAP_MISSING_PLAYER_SPAWN_POS, cub_data);
}

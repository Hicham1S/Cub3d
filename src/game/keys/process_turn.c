/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:07:31 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:07:32 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	turn_left(t_cub_data *data)
{
	float	step;

	step = SENSITIVITY * M_PI / 180;
	data->player_data.angle = fmod(data->player_data.angle - step, 2 * M_PI);
	if (data->player_data.angle < 0)
		data->player_data.angle += 2 * M_PI;
}

void	turn_right(t_cub_data *data)
{
	float	step;

	step = SENSITIVITY * M_PI / 180;
	data->player_data.angle = fmod(data->player_data.angle + step, 2 * M_PI);
	if (data->player_data.angle < 0)
		data->player_data.angle += 2 * M_PI;
}

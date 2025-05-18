/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_motion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:07:26 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:07:28 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static int	is_walkable(t_cub_data *data, float x, float y)
{
	if (data->settings.map[(int)y][(int)x] != '1')
		return (1);
	return (0);
}

void	move_forward(t_cub_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x + PLAYER_SPEED * cos(data->player_data.angle);
	new_y = data->player_data.y + PLAYER_SPEED * sin(data->player_data.angle);
	if (is_walkable(data, new_x, data->player_data.y))
		data->player_data.x = new_x;
	if (is_walkable(data, data->player_data.x, new_y))
		data->player_data.y = new_y;
}

void	move_backward(t_cub_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x - PLAYER_SPEED * cos(data->player_data.angle);
	new_y = data->player_data.y - PLAYER_SPEED * sin(data->player_data.angle);
	if (is_walkable(data, new_x, data->player_data.y))
		data->player_data.x = new_x;
	if (is_walkable(data, data->player_data.x, new_y))
		data->player_data.y = new_y;
}

void	move_left(t_cub_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x + STRAFE_SPEED * sin(data->player_data.angle);
	new_y = data->player_data.y - STRAFE_SPEED * cos(data->player_data.angle);
	if (is_walkable(data, new_x, data->player_data.y))
		data->player_data.x = new_x;
	if (is_walkable(data, data->player_data.x, new_y))
		data->player_data.y = new_y;
}

void	move_right(t_cub_data *data)
{
	float	new_x;
	float	new_y;

	new_x = data->player_data.x - STRAFE_SPEED * sin(data->player_data.angle);
	new_y = data->player_data.y + STRAFE_SPEED * cos(data->player_data.angle);
	if (is_walkable(data, new_x, data->player_data.y))
		data->player_data.x = new_x;
	if (is_walkable(data, data->player_data.x, new_y))
		data->player_data.y = new_y;
}

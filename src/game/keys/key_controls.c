/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:07:20 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:07:22 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	update_key_state(t_cub_data *data, int keycode, bool state)
{
	if (keycode == W)
		data->keys.keys[KEY_W] = state;
	else if (keycode == A)
		data->keys.keys[KEY_A] = state;
	else if (keycode == S)
		data->keys.keys[KEY_S] = state;
	else if (keycode == D)
		data->keys.keys[KEY_D] = state;
	else if (keycode == LEFT_ARROW)
		data->keys.keys[KEY_LEFT] = state;
	else if (keycode == RIGHT_ARROW)
		data->keys.keys[KEY_RIGHT] = state;
}

int	key_press(int keycode, t_cub_data *data)
{
	if (keycode == ESC)
		cub_exit(SUCCESS, data);
	update_key_state(data, keycode, true);
	return (0);
}

int	key_release(int keycode, t_cub_data *data)
{
	update_key_state(data, keycode, false);
	return (0);
}

void	handle_keys(t_cub_data *data)
{
	if (data->keys.keys[KEY_W])
		move_forward(data);
	if (data->keys.keys[KEY_S])
		move_backward(data);
	if (data->keys.keys[KEY_A])
		move_left(data);
	if (data->keys.keys[KEY_D])
		move_right(data);
	if (data->keys.keys[KEY_LEFT])
		turn_left(data);
	if (data->keys.keys[KEY_RIGHT])
		turn_right(data);
}

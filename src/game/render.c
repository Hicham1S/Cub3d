/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:08:13 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:08:14 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	update_gun_frame(long *last_time, int *gun_frame)
{
	long	current_time;

	current_time = get_current_time_in_ms();
	if (current_time - *last_time > 1500)
	{
		*last_time = current_time;
		*gun_frame = (*gun_frame + 1) % 2;
	}
}

static void	render_frame(t_cub_data *data)
{
	fill_background(data, 0, 0);
	raycasting(data);
	draw_minimap(data, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->mlx.img, 0, 0);
}

int	render(t_cub_data *data)
{
	static long	last_time = 0;
	static int	gun_frame = 0;

	update_gun_frame(&last_time, &gun_frame);
	handle_keys(data);
	render_frame(data);
	return (0);
}

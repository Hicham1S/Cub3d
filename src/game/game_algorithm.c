/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:08:07 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:08:09 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	render_background_and_3d(t_cub_data *data)
{
	fill_background(data, 0, 0);
	raycasting(data);
}

static void	render_minimap_and_display(t_cub_data *data)
{
	draw_minimap(data, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx_ptr,
		data->mlx.win_ptr, data->mlx.img, 0, 0);
}

static void	hook_render_loop(t_cub_data *data)
{
	mlx_loop_hook(data->mlx.mlx_ptr, render, data);
}

static void	game_algorithm(t_cub_data *data)
{
	render_background_and_3d(data);
	render_minimap_and_display(data);
	hook_render_loop(data);
}

void	game_loop(t_cub_data *data)
{
	game_algorithm(data);
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx.win_ptr, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx.win_ptr, 17, 1L << 17,
		(void *)free_everything, data);
	mlx_loop(data->mlx.mlx_ptr);
}

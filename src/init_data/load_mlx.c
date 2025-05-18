/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:58:33 by mjamil            #+#    #+#             */
/*   Updated: 2025/05/18 20:58:35 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	load_textures_imgs(t_cub_data *data)
{
	data->utils.minimap.frame.img_ptr = \
		mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, FRAME,
			&data->utils.minimap.frame.width,
			&data->utils.minimap.frame.height);
}

static void	load_walls_imgs(t_cub_data *data)
{
	data->walls.north.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.n_texture_path,
			&data->walls.north.width, &data->walls.north.height);
	data->walls.south.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.s_texture_path,
			&data->walls.south.width, &data->walls.south.height);
	data->walls.east.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.e_texture_path,
			&data->walls.east.width, &data->walls.east.height);
	data->walls.west.img_ptr = mlx_xpm_file_to_image(
			data->mlx.mlx_ptr, data->settings.w_texture_path,
			&data->walls.west.width, &data->walls.west.height);
}

static void	check_loaded_imgs(t_cub_data *data)
{
	if (!data->walls.west.img_ptr || !data->walls.east.img_ptr || \
		!data->walls.south.img_ptr || !data->walls.north.img_ptr)
		cub_exit(MLX_ERROR, data);
}

void	load_mlx(t_cub_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		cub_exit(MLX_ERROR, data);
	mlx_get_screen_size(data->mlx.mlx_ptr, &data->mlx.win_width,
		&data->mlx.win_height);
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			data->mlx.win_width, data->mlx.win_height, "cub3D");
	if (!data->mlx.win_ptr)
		cub_exit(MLX_ERROR, data);
	mlx_mouse_hide(data->mlx.mlx_ptr, data->mlx.win_ptr);
	data->mlx.img = mlx_new_image(data->mlx.mlx_ptr, data->mlx.win_width,
			data->mlx.win_height);
	if (!data->mlx.img)
		cub_exit(MLX_ERROR, data);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img,
			&data->mlx.bits, &data->mlx.line_len, &data->mlx.edian);
	load_walls_imgs(data);
	load_textures_imgs(data);
	check_loaded_imgs(data);
	get_imgs_addr(data);
}

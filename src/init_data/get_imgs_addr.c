/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_imgs_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:58:17 by mjamil            #+#    #+#             */
/*   Updated: 2025/05/18 20:58:20 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	get_imgs_adresses(t_cub_data *data)
{
	data->utils.minimap.frame.data = mlx_get_data_addr(
			data->utils.minimap.frame.img_ptr, &data->utils.minimap.frame.bpp,
			&data->utils.minimap.frame.size_line,
			&data->utils.minimap.frame.endian);
}

static void	get_walls_addr(t_cub_data *data)
{
	data->walls.north.data = mlx_get_data_addr(
			data->walls.north.img_ptr, &data->walls.north.bpp,
			&data->walls.north.size_line, &data->walls.north.endian);
	data->walls.south.data = mlx_get_data_addr(
			data->walls.south.img_ptr, &data->walls.south.bpp,
			&data->walls.south.size_line, &data->walls.south.endian);
	data->walls.east.data = mlx_get_data_addr(
			data->walls.east.img_ptr, &data->walls.east.bpp,
			&data->walls.east.size_line, &data->walls.east.endian);
	data->walls.west.data = mlx_get_data_addr(
			data->walls.west.img_ptr, &data->walls.west.bpp,
			&data->walls.west.size_line, &data->walls.west.endian);
}

void	get_imgs_addr(t_cub_data *data)
{
	get_imgs_adresses(data);
	get_walls_addr(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:07:41 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:07:47 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	get_sx_sy(int var1, int var2)
{
	if (var1 < var2)
		return (1);
	return (-1);
}

void	plot_line_bresenham(t_cub_data *data, int start[2], int end[2])
{
	t_bresenham	var;

	var.dx_dy[0] = ft_abs(end[0] - start[0]);
	var.dx_dy[1] = -ft_abs(end[1] - start[1]);
	var.sx_sy[0] = (start[0] < end[0]) ? 1 : -1;
	var.sx_sy[1] = (start[1] < end[1]) ? 1 : -1;
	var.err = var.dx_dy[0] + var.dx_dy[1];
	
	while (start[0] != end[0] || start[1] != end[1])
	{
		cub_draw_pixel(data, start[0], start[1], RED);
		var.e2 = 2 * var.err;
		if (var.e2 >= var.dx_dy[1])
		{
			var.err += var.dx_dy[1];
			start[0] += var.sx_sy[0];
		}
		if (var.e2 <= var.dx_dy[0])
		{
			var.err += var.dx_dy[0];
			start[1] += var.sx_sy[1];
		}
	}
	cub_draw_pixel(data, end[0], end[1], RED);
	
}

void	cub_draw_pixel(t_cub_data *data, int x, int y, int color)
{
	char			*pixel_addr;
	unsigned int	*pixel;

	if (!data || x < 0 || y < 0 || x >= data->mlx.win_width
		|| y >= data->mlx.win_height)
		return ;
	pixel_addr = data->mlx.addr
		+ (y * data->mlx.line_len + x * (data->mlx.bits / 8));
	pixel = (unsigned int *)pixel_addr;
	*pixel = (unsigned int)color;
}

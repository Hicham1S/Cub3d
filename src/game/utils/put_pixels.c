/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:07:41 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 21:44:28 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	get_sx_sy(int var1, int var2)
{
	if (var1 < var2)
		return (1);
	return (-1);
}

void	init_bresenham(t_bresenham *v, int start[2], int end[2])
{
	v->x = start[0];
	v->y = start[1];
	v->dx_dy[0] = ft_abs(end[0] - start[0]);
	v->dx_dy[1] = -ft_abs(end[1] - start[1]);
	if (start[0] < end[0])
		v->sx_sy[0] = 1;
	else
		v->sx_sy[0] = -1;
	if (start[1] < end[1])
		v->sx_sy[1] = 1;
	else
		v->sx_sy[1] = -1;
	v->err = v->dx_dy[0] + v->dx_dy[1];
}

void	plot_line_bresenham(t_cub_data *data, int start[2], int end[2])
{
	t_bresenham	var;

	init_bresenham(&var, start, end);
	while (var.x != end[0] || var.y != end[1])
	{
		cub_draw_pixel(data, var.x, var.y, RED);
		var.e2 = 2 * var.err;
		if (var.e2 >= var.dx_dy[1])
		{
			var.err += var.dx_dy[1];
			var.x += var.sx_sy[0];
		}
		if (var.e2 <= var.dx_dy[0])
		{
			var.err += var.dx_dy[0];
			var.y += var.sx_sy[1];
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

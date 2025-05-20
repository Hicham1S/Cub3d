/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:07:54 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:07:56 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

int	scale_player_pos(float pos)
{
	pos *= MINIMAP_SIZE / (RANGE * 2);
	return (pos);
}

void	fill_cell(t_cub_data *data, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < MINIMAP_SIZE && y < MINIMAP_SIZE)
		cub_draw_pixel(data, x, y, color);
}

void	minimap_frame(t_cub_data *data)
{
	t_img	*frame;
	int		x;
	int		y;
	int		color;

	frame = &data->utils.minimap.frame;
	y = 0;
	while (y < frame->height)
	{
		x = 0;
		while (x < frame->width)
		{
			color = *(int *)(frame->data + y * \
				frame->size_line + x * (frame->bpp / 8));
			if ((color & 0xFFFFFF) != BLACK)
			{
				*(int *)(data->mlx.addr + y * \
					data->mlx.line_len + x * (data->mlx.bits / 8)) = color;
			}
			x++;
		}
		y++;
	}
}

long	get_current_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

float	ft_fabs(float value)
{
	if (value < 0)
		return (-value);
	return (value);
}

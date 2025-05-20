/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:06:38 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:06:38 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static int	create_trgb(unsigned char r, unsigned char g, unsigned char b)
{
	int	t;

	t = 0;
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

static int	get_floor_color(t_cub_data *data)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = data->settings.floor_color->r;
	g = data->settings.floor_color->g;
	b = data->settings.floor_color->b;
	return (create_trgb(r, g, b));
}

static int	get_ceiling_color(t_cub_data *data)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = data->settings.ceiling_color->r;
	g = data->settings.ceiling_color->g;
	b = data->settings.ceiling_color->b;
	return (create_trgb(r, g, b));
}

void	fill_background(t_cub_data *data, int x, int y)
{
	int	ceiling_color;
	int	floor_color;
	int	half_height;

	ceiling_color = get_ceiling_color(data);
	floor_color = get_floor_color(data);
	half_height = data->mlx.win_height / 2;
	while (y < data->mlx.win_height)
	{
		x = 0;
		while (x < data->mlx.win_width)
		{
			if (y < half_height)
				cub_draw_pixel(data, x, y, ceiling_color);
			else
				cub_draw_pixel(data, x, y, floor_color);
			x++;
		}
		y++;
	}
}

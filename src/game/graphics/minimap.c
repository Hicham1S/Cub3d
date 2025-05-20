/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:06:44 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 21:45:52 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	draw_elem(t_cub_data *data, int i[2], int color, float offset[2])
{
	int	start[2];
	int	end[2];
	int	x;
	int	y;

	start[0] = (i[1] - offset[0]) * data->utils.minimap.cell_width;
	start[1] = (i[0] - offset[1]) * data->utils.minimap.cell_height;
	end[0] = start[0] + data->utils.minimap.cell_width;
	end[1] = start[1] + data->utils.minimap.cell_height;
	y = start[1];
	while (y <= end[1])
	{
		x = start[0];
		while (x <= end[0])
			fill_cell(data, x++, y, color);
		y++;
	}
}

void	draw_map_elements(t_cub_data *dat, int i[2], float offset[2])
{
	i[0] = (int)offset[1];
	while (i[0] < (int)offset[1] + 2 * RANGE)
	{
		i[1] = (int)offset[0];
		while (i[1] < (int)offset[0] + 2 * RANGE)
		{
			if (i[0] >= 0 && i[0] < dat->utils.map_height
				&& i[1] >= 0
				&& i[1] < ft_strlen1(dat->settings.map[i[0]]))
			{
				if (dat->settings.map[i[0]][i[1]] == '1')
					draw_elem(dat, i, WHITE, offset);
				else if (dat->settings.map[i[0]][i[1]] == '0'
					|| dat->settings.map[i[0]][i[1]]
					== dat->player_data.pole)
					draw_elem(dat, i, GREY, offset);
			}
			i[1]++;
		}
		i[0]++;
	}
}

void	draw_player_on_minimap(t_cub_data *data, int x, int y)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	start_x = MINIMAP_SIZE / 2 - PLAYER_DOT_SIZE / 2;
	start_y = MINIMAP_SIZE / 2 - PLAYER_DOT_SIZE / 2;
	end_x = start_x + PLAYER_DOT_SIZE;
	end_y = start_y + PLAYER_DOT_SIZE;
	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
			cub_draw_pixel(data, x++, y, RED);
		y++;
	}
}

void	draw_view_direction(t_cub_data *data)
{
	int	start[2];
	int	end[2];
	int	len;

	len = 15;
	start[0] = MINIMAP_SIZE / 2;
	start[1] = MINIMAP_SIZE / 2;
	end[0] = start[0] + len * cos(data->player_data.angle);
	end[1] = start[1] + len * sin(data->player_data.angle);
	plot_line_bresenham(data, start, end);
}

void	draw_minimap(t_cub_data *data, int x, int y)
{
	int		i[2];
	float	offset[2];

	i[0] = 0;
	i[1] = 0;
	data->player_data.mm_x = scale_player_pos(data->player_data.x);
	data->player_data.mm_y = scale_player_pos(data->player_data.y);
	offset[0] = data->player_data.mm_x
		/ data->utils.minimap.cell_width - RANGE;
	offset[1] = data->player_data.mm_y
		/ data->utils.minimap.cell_height - RANGE;
	while (y < 231)
	{
		x = -1;
		while (++x < 231)
			cub_draw_pixel(data, x, y, BLACK);
		y++;
	}
	draw_map_elements(data, i, offset);
	draw_player_on_minimap(data, data->player_data.mm_x,
		data->player_data.mm_y);
	draw_view_direction(data);
	minimap_frame(data);
}

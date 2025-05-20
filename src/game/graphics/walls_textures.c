/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:06:54 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 21:31:05 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static int	get_texture_color(t_img *texture, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = texture->data + (y * texture->size_line
			) + (x * (texture->bpp / 8));
	return (*(int *)pixel_addr);
}

static void	get_wall_texture_coords(t_cub_data *data,
		t_ray_cast *ray, t_img *texture)
{
	double	wall_hit;

	if (ray->side == 0)
		wall_hit = data->player_data.y + ray->raw_wall_dist * ray->ray_dir_y;
	else
		wall_hit = data->player_data.x + ray->raw_wall_dist * ray->ray_dir_x;
	wall_hit -= floor(wall_hit);
	ray->texture_x = (int)(wall_hit * texture->width);
	if ((ray->side == 0 && ray->ray_dir_x < 0) || (
			ray->side == 1 && ray->ray_dir_y > 0))
		ray->texture_x = texture->width - ray->texture_x - 1;
}

static void	put_wall(t_cub_data *data, t_ray_cast *ray, t_img *texture)
{
	int				y;
	int				d;
	unsigned int	color;

	get_wall_texture_coords(data, ray, texture);
	y = ray->line_draw_start;
	while (y < ray->line_draw_end)
	{
		d = y - data->mlx.win_height / 2 + ray->line_height / 2;
		ray->texture_y = (d * texture->height) / ray->line_height;
		if (ray->texture_y < 0)
			ray->texture_y = 0;
		if (ray->texture_y >= texture->height)
			ray->texture_y = texture->height - 1;
		color = get_texture_color(texture, ray->texture_x, ray->texture_y);
		cub_draw_pixel(data, ray->column, y, color);
		y++;
	}
}

void	put_wall_texture(t_cub_data *data, t_ray_cast *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			put_wall(data, ray, &data->walls.west);
		else
			put_wall(data, ray, &data->walls.east);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			put_wall(data, ray, &data->walls.north);
		else
			put_wall(data, ray, &data->walls.south);
	}
}

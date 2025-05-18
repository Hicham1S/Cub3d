/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:06:50 by hsarraj           #+#    #+#             */
/*   Updated: 2025/05/18 18:06:52 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	perform_dda(t_cub_data *data, t_ray_cast *ray)
{
	char	value;

	ray->hit = false;
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		value = data->settings.map[ray->map_y][ray->map_x];
		if (value == '1')
			ray->hit = true;
	}
}

static void	init_ray_steps(t_cub_data *data, t_ray_cast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player_data.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player_data.x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player_data.y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player_data.y)
			* ray->delta_dist_y;
	}
}

static void	compute_raycasting_values(t_cub_data *data, t_ray_cast *ray)
{
	float	fov_rad;

	fov_rad = FOV * (M_PI / 180.0);
	ray->ray_angle = data->player_data.angle - (fov_rad / 2.0)
		+ ((float)ray->column / data->mlx.win_width) * fov_rad;
	ray->ray_dir_x = cos(ray->ray_angle);
	ray->ray_dir_y = sin(ray->ray_angle);
	ray->delta_dist_x = ft_fabs(1.0 / ray->ray_dir_x);
	ray->delta_dist_y = ft_fabs(1.0 / ray->ray_dir_y);
	init_ray_steps(data, ray);
}

static void	get_wall_dist(t_cub_data *data, t_ray_cast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player_data.x
				+ (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player_data.y
				+ (1 - ray->step_y) / 2.0) / ray->ray_dir_y;
	ray->raw_wall_dist = ray->perp_wall_dist;
	ray->perp_wall_dist *= cos(ray->ray_angle - data->player_data.angle);
	ray->line_height = (int)(data->mlx.win_height / ray->perp_wall_dist);
	ray->line_draw_start = -ray->line_height / 2 + data->mlx.win_height / 2;
	if (ray->line_draw_start < 0)
		ray->line_draw_start = 0;
	ray->line_draw_end = ray->line_height / 2 + data->mlx.win_height / 2;
	if (ray->line_draw_end >= data->mlx.win_height)
		ray->line_draw_end = data->mlx.win_height - 1;
}

void	raycasting(t_cub_data *data)
{
	data->ray.column = 0;
	while (data->ray.column < data->mlx.win_width)
	{
		data->ray.map_x = (int)data->player_data.x;
		data->ray.map_y = (int)data->player_data.y;
		compute_raycasting_values(data, &data->ray);
		perform_dda(data, &data->ray);
		get_wall_dist(data, &data->ray);
		put_wall_texture(data, &data->ray);
		data->ray.column++;
	}
}

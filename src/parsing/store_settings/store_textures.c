/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:59:08 by mjamil            #+#    #+#             */
/*   Updated: 2025/05/18 20:59:10 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	texture_file_opening_test(
	t_cub_data *cub_data,
	int settings_fd,
	char **line_elements,
	char direction)
{
	int	fd;

	fd = open(line_elements[1], O_RDONLY);
	if (fd == -1)
	{
		free_double_array(&line_elements);
		reach_eof_to_avoid_leaks(NULL, settings_fd);
		close(settings_fd);
		if (direction == 'E')
			cub_exit(E_BAD_FILE_PATH, cub_data);
		else if (direction == 'N')
			cub_exit(N_BAD_FILE_PATH, cub_data);
		else if (direction == 'S')
			cub_exit(S_BAD_FILE_PATH, cub_data);
		else if (direction == 'W')
			cub_exit(W_BAD_FILE_PATH, cub_data);
	}
	close(fd);
}

static void	store_texture_path_ptr(
	t_cub_data *cub_data,
	char direction,
	char *path)
{
	if (direction == 'E')
		cub_data->settings.e_texture_path = path;
	else if (direction == 'N')
		cub_data->settings.n_texture_path = path;
	else if (direction == 'S')
		cub_data->settings.s_texture_path = path;
	else if (direction == 'W')
		cub_data->settings.w_texture_path = path;
}

static void	check_for_duplicate_settings(
	t_cub_data *cub_data,
	char direction,
	char **line_elements,
	int fd)
{
	if ((direction == 'E' && cub_data->settings.e_texture_path != NULL)
		|| (direction == 'N' && cub_data->settings.n_texture_path != NULL)
		|| (direction == 'S' && cub_data->settings.s_texture_path != NULL)
		|| (direction == 'W' && cub_data->settings.w_texture_path != NULL))
	{
		free_double_array(&line_elements);
		reach_eof_to_avoid_leaks(NULL, fd);
		close (fd);
		cub_exit(DUPLICATED_SETTING, cub_data);
	}
}

int	store_texture_path(t_cub_data *cub_data, char **line_elements, int fd)
{
	char	direction;
	char	*path;

	path = NULL;
	if (ft_strcmp("EA", line_elements[0]) == 0
		|| ft_strcmp("NO", line_elements[0]) == 0
		|| ft_strcmp("SO", line_elements[0]) == 0
		|| ft_strcmp("WE", line_elements[0]) == 0)
	{
		direction = line_elements[0][0];
		check_for_duplicate_settings(cub_data, direction, line_elements, fd);
		texture_file_opening_test(cub_data, fd, line_elements, direction);
		path = ft_strdup(line_elements[1]);
		if (!path)
		{
			reach_eof_to_avoid_leaks(NULL, fd);
			close(fd);
			free_double_array(&line_elements);
			cub_exit(OTHER, cub_data);
		}
		store_texture_path_ptr(cub_data, direction, path);
		return (0);
	}
	return (1);
}

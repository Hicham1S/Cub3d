/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:58:56 by mjamil            #+#    #+#             */
/*   Updated: 2025/05/18 20:58:58 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static void	free_and_exit(t_map_params *params)
{
	free(params->line);
	close(params->fd);
	cub_exit(OTHER, params->cub_data);
}

static void	copy_old_to_new(
	char **old,
	char **new,
	int length,
	t_map_params *params)
{
	int	i;

	i = 0;
	while (i < length)
	{
		new[i] = ft_strdup(old[i]);
		if (!new[i])
			free_and_exit(params);
		i++;
	}
}

static void	allocate_new_double_array(t_map_params *params)
{
	char	**new;
	int		length;
	char	*not_trimed;

	length = double_array_len(params->old_map);
	new = malloc(sizeof(char *) * (length + 2));
	if (!new)
		free_and_exit(params);
	if (length > 0)
		copy_old_to_new(params->old_map, new, length, params);
	not_trimed = ft_strdup(params->line);
	if (!not_trimed)
		free_and_exit(params);
	new[length] = ft_strtrim(not_trimed, "\n");
	if (!new[length])
	{
		free(not_trimed);
		free_and_exit(params);
	}
	free(not_trimed);
	new[length + 1] = NULL;
	free_double_array(&params->old_map);
	params->old_map = new;
}

static void	no_map(t_cub_data *cub_data, int fd)
{
	close(fd);
	cub_exit(NO_MAP_IN_FILE, cub_data);
}

void	store_map(t_cub_data *cub_data, char *old_line, int fd)
{
	char			*line;
	t_map_params	params;

	line = old_line;
	params.fd = fd;
	if (!line)
		no_map(cub_data, fd);
	while (line && is_only_spaces(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		params.old_map = cub_data->settings.map;
		params.line = line;
		params.cub_data = cub_data;
		allocate_new_double_array(&params);
		cub_data->settings.map = params.old_map;
		free(line);
		line = get_next_line(fd);
	}
	check_map_validity(cub_data, fd);
	store_player_pos(cub_data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsarraj <hsarraj@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:06:25 by afarachi          #+#    #+#             */
/*   Updated: 2025/05/18 18:12:23 by hsarraj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	check_file_extention(struct s_cub_data *cub_data)
{
	char	*ext;

	ext = ft_strrchr(cub_data->utils.map_path, '.');
	if (!ext || ft_strcmp(ext, FILE_EXTENTION) != 0)
	{
		cub_exit(BAD_FILE_EXTENTION, cub_data);
	}
}

void	parsing(struct s_cub_data *cub_data)
{
	init_data(cub_data);
	if (cub_data->utils.argc != ARGUMENTS_REQUIRED)
	{
		cub_exit(BAD_ARGUMENTS, cub_data);
	}
	cub_data->utils.map_path = cub_data->utils.argv[1];
	check_file_extention(cub_data);
	extract_settings(cub_data);
}

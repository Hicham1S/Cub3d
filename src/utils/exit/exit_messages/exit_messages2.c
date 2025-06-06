/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:43:40 by afarachi          #+#    #+#             */
/*   Updated: 2025/05/18 20:59:58 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3D.h"

void	east_bad_file_path_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the east texture file.\n\033[0m",
		STDERR_FILENO);
}

void	north_bad_file_path_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the north texture file.\n\033[0m",
		STDERR_FILENO);
}

void	south_bad_file_path_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the south texture file.\n\033[0m",
		STDERR_FILENO);
}

void	west_bad_file_path_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mCouldn't open the west texture file.\n\033[0m",
		STDERR_FILENO);
}

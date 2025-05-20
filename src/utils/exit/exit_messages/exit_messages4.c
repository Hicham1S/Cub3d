/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:43:48 by afarachi          #+#    #+#             */
/*   Updated: 2025/05/18 21:00:07 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3D.h"

void	mlx_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mMLX error.\n\033[0m",
		STDERR_FILENO);
}

void	map_wrong_character_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mWrong map character.\n\033[0m",
		STDERR_FILENO);
}

void	map_duplicated_player_spawn_pos(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mDuplicated player spawn position.\n\033[0m",
		STDERR_FILENO);
}

void	map_missing_player_spawn_pos(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mMissing player spawn position.\n\033[0m",
		STDERR_FILENO);
}

void	map_missing(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mNo map found in a file\n\033[0m",
		STDERR_FILENO);
}

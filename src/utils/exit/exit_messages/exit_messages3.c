/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_messages3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odib <odib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:43:44 by afarachi          #+#    #+#             */
/*   Updated: 2024/12/05 11:14:36 by odib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3D.h"

void	bad_identifier_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mBad identifier or some ", STDERR_FILENO);
	ft_putstr_fd("settings are missing.\n\033[0m", STDERR_FILENO);
}

void	bad_color_code_format_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mBad color code format.\n",
		STDERR_FILENO);
	ft_putstr_fd("Should be 'R,G,B' and 0 <= color <= 255.\n\033[0m",
		STDERR_FILENO);
}

void	missing_setting_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mMissing setting.\n\033[0m",
		STDERR_FILENO);
}

void	missing_map_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mMissing map.\n\033[0m",
		STDERR_FILENO);
}

void	unclosed_map_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("\033[0;31mUnclosed map.\n\033[0m",
		STDERR_FILENO);
}

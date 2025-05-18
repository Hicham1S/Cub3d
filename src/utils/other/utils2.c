/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:44:14 by afarachi          #+#    #+#             */
/*   Updated: 2025/05/18 21:00:31 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

bool	is_player_spawn_pos(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	reach_eof_to_avoid_leaks(char *line, int fd)
{
	line = get_next_line(fd);
	while (1)
	{
		if (line == NULL)
			return ;
		free(line);
		line = get_next_line(fd);
	}
}

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

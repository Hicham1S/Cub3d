/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:14:08 by odib              #+#    #+#             */
/*   Updated: 2025/05/18 21:00:26 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	free_double_array(char ***array_ptr)
{
	int	i;

	i = 0;
	if (*array_ptr)
	{
		while ((*array_ptr)[i])
		{
			free((*array_ptr)[i]);
			(*array_ptr)[i] = NULL;
			i++;
		}
		free(*array_ptr);
		*array_ptr = NULL;
	}
}

int	double_array_len(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
			i++;
	}
	return (i);
}

bool	is_only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

bool	is_space(char check)
{
	if (check != ' ' && check != '\n' && check != '\t')
		return (false);
	return (true);
}

int	ft_strcmp1(const char *first, const char *second)
{
	while (*first && (*first == *second))
	{
		first++;
		second++;
	}
	return (*(unsigned char *)first - *(unsigned char *)second);
}

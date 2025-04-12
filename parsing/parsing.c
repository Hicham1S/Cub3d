/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:49:11 by mjamil            #+#    #+#             */
/*   Updated: 2025/04/12 15:19:09 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char **realloc_lines_array(char **lines, int count, char *line)
{
	char **new_lines;
	int i;

	new_lines = malloc(sizeof(char *) * (count + 2));
	if (!new_lines)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_lines[i] = lines[i];
		i++;
	}
	new_lines[i++] = line;
	new_lines[i] = NULL;
	free(lines);
	return (new_lines);
}

char **read_file_line(char *file)
{
	int fd;
	int count;
	char *line;
	char **lines;

	count = 0;
	lines = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (NULL);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		lines = realloc_lines_array(lines, count, ft_strdup(line));
		free(line);
		count++;
	}
	close(fd);
	return (lines);
}


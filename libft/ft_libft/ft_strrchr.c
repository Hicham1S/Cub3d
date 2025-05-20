/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:29:51 by afarachi          #+#    #+#             */
/*   Updated: 2025/05/19 16:54:06 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	size_t			i;
	unsigned char	chr;

	chr = c;
	i = ft_strlen(s);
	str = (char *)s + i;
	if (c == '\0')
		return (str++);
	while (str >= s)
	{
		if (*str == chr)
			return (str);
		str--;
	}
	str = NULL;
	return (str);
}

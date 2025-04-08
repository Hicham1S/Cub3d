/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dawwad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:20:51 by dawwad            #+#    #+#             */
/*   Updated: 2024/06/13 14:20:54 by dawwad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int x)
{
	if (x >= 'A' && x <= 'Z')
		x += 32;
	return (x);
}

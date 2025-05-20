/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjamil <mjamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:43:59 by afarachi          #+#    #+#             */
/*   Updated: 2025/05/18 21:00:17 by mjamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	cub_exit(t_errors code, t_cub_data *cub_data)
{
	if (code < sizeof(cub_data->utils.exit_funcs)
		/ sizeof(cub_data->utils.exit_funcs[0]))
	{
		cub_data->utils.exit_funcs[code]();
	}
	free_everything(cub_data);
	if (code == SUCCESS)
		exit(SUCCESS);
	exit(EXIT_FAILURE);
}

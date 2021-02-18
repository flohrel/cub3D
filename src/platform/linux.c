/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:48:49 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 16:27:07 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platform/linux.h"

int		exit_program(t_vars *vars)
{
	while (++i < 5)
		if (param->texture_path[i])
			free(param->texture_path[i]);
	if (vars->screen->image)
		mlx_destroy_image(vars->mlx, vars->screen->image);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:38:45 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/17 16:33:26 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "platform/mac.h"

int		exit_program(t_vars *vars)
{
	if (vars->screen->image)
		mlx_destroy_image(vars->mlx, vars->screen->image);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		free(vars->mlx);
	exit(0);
	return (0);
}

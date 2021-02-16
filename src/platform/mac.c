/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:38:45 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/16 16:19:16 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "platform/mac.h"

int		exit_program(t_vars *vars)
{
	ft_lstclear(&vars->textures, destroy_textures);
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img->image);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
}

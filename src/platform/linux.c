/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:48:49 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 20:56:44 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platform/linux.h"

int		exit_program(t_vars *vars)
{
	int		i;
	t_param	*param;
	t_img	*texture;
	t_img	*screen;

	param = vars->param;
	i = -1;
	while (++i < 5)
	{
		texture = vars->textures[i];
		if (param->texture_path[i])
			free(param->texture_path[i]);
		if (vars->mlx && texture && texture->image)
			mlx_destroy_image(vars->mlx, texture->image);
	}
	screen = vars->screen;
	if (screen && screen->image)
		mlx_destroy_image(vars->mlx, screen->image);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

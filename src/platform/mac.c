/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:38:45 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 19:33:39 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "platform/mac.h"

int		exit_program(t_vars *vars)
{
	int		i;
	t_param	*param;

	i = -1;
	param = vars->param;
	while (++i < 5)
	{
		if (param->texture_path[i])
			free(param->texture_path[i]);
		if (vars->textures[i])
			mlx_destroy_image(vars->mlx, vars->textures[i]->image);
	}
	if (vars->screen->image)
		mlx_destroy_image(vars->mlx, vars->screen->image);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		free(vars->mlx);
	exit(0);
	return (0);
}

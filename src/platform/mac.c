/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:38:45 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/25 01:41:23 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "platform/mac.h"

void	get_screen_size(t_vars *vars, t_param *param)
{
	(void)vars;
	(void)param;
	return ;
}

void	free_textures(t_vars *vars, t_param *param)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		if (param->texture_path[i])
			free(param->texture_path[i]);
		if (vars->textures[i].image)
			mlx_destroy_image(vars->mlx, vars->textures[i].image);
	}
}

void	free_map(t_param *param)
{
	int	i;
	
	i = -1;
	if (param->map)
	{
		while (++i < param->map_height)
			if (param->map[i])
				free(param->map[i]);
		free(param->map);
	}
}

int		exit_program(t_vars *vars)
{
	t_img	*screen;

	free_textures(vars, vars->param);
	screen = vars->screen;
	free_map(vars->param);
	if (vars->mlx)
	{
		if (screen->image)
			mlx_destroy_image(vars->mlx, screen->image);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
	}
	exit(0);
	return (0);
}

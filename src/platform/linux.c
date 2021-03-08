/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:48:49 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/08 16:56:21 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "platform/linux.h"

void	get_screen_size(t_vars *vars, t_param *param)
{
	int		max_width;
	int		max_height;

	mlx_get_screen_size(vars->mlx, &max_width, &max_height);
	if (max_width < param->win_width)
		param->win_width = max_width;
	if (max_height < param->win_height)
		param->win_height = max_height;
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
		while (++i < param->map_width)
			if (param->map[i])
				free(param->map[i]);
		free(param->map);
	}
}

int		exit_program(t_vars *vars)
{
	t_img	*screen;
	t_data	*data;
	t_param	*param;

	data = vars->data;
	param = vars->param;
	free_textures(vars, vars->param);
	if (data && data->zbuffer)
		free(vars->data->zbuffer);
	if (param->map)
		free_map(vars->param);
	if (vars->sprites)
		ft_lstclear(&vars->sprites, del_sprite);
	screen = vars->screen;
	if (vars->mlx)
	{
		if (screen->image)
			mlx_destroy_image(vars->mlx, screen->image);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
	return (0);
}

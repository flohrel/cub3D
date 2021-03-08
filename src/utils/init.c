/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 18:51:44 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/08 16:59:27 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

int		init_data(t_vars *vars, t_param *param, t_data *data, t_time *time)
{
	data->pos.x = param->map_width - param->pos.x - 1;
	data->pos.y = param->pos.y;
	time->time = 0;
	time->old_time = 0;
	vars->kbflags = 0;
	get_screen_size(vars, param);
	data->zbuffer = ft_calloc(param->win_width, sizeof(double));
	if (!data->zbuffer)
		return (ERROR);
	return (SUCCESS);
}

void	init_vars(t_vars *vars, t_param *param, t_data *data, t_img *screen)
{
	int		i;

	errno = 0;
	vars->save = false;
	i = -1;
	while (++i < 5)
	{
		param->texture_path[i] = NULL;
		vars->textures[i].image = NULL;
	}
	param->map_height = 0;
	param->map_width = 0;
	param->map = NULL;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit_program(vars);
	vars->win = NULL;
	vars->sprites = NULL;
	screen->image = NULL;
	data->zbuffer = NULL;
}

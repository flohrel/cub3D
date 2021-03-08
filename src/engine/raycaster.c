/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:35:07 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/08 15:21:12 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	init_vect(t_data *data)
{
	data->raydir.x = data->dir.x + data->plane.x * data->xcam;
	data->raydir.y = data->dir.y + data->plane.y * data->xcam;
	data->map.x = (int)data->pos.x;
	data->map.y = (int)data->pos.y;
	data->deltadist.x = fabs(1 / data->raydir.x);
	data->deltadist.y = fabs(1 / data->raydir.y);
}

void	get_sidedist(t_data *data)
{
	if (data->raydir.x < 0)
	{
		data->step.x = -1;
		data->sidedist.x = (data->pos.x - data->map.x)
			* data->deltadist.x;
	}
	else
	{
		data->step.x = 1;
		data->sidedist.x = (data->map.x + 1.0 - data->pos.x)
			* data->deltadist.x;
	}
	if (data->raydir.y < 0)
	{
		data->step.y = -1;
		data->sidedist.y = (data->pos.y - data->map.y)
			* data->deltadist.y;
	}
	else
	{
		data->step.y = 1;
		data->sidedist.y = (data->map.y + 1.0 - data->pos.y)
			* data->deltadist.y;
	}
}

void	dda(t_data *data, int **map)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sidedist.x < data->sidedist.y)
		{
			data->sidedist.x += data->deltadist.x;
			data->map.x += data->step.x;
			data->side = 1;
			if (data->step.x < 0)
				data->side = 0;
		}
		else
		{
			data->sidedist.y += data->deltadist.y;
			data->map.y += data->step.y;
			data->side = 3;
			if (data->step.y < 0)
				data->side = 2;
		}
		if (map[data->map.x][data->map.y] > 0)
			hit = 1;
	}
}

void	get_walldist(t_data *data)
{
	if (data->side < 2)
		data->perpwalldist = (data->map.x - data->pos.x
			+ (1 - data->step.x) / 2) / data->raydir.x;
	else
		data->perpwalldist = (data->map.y - data->pos.y
			+ (1 - data->step.y) / 2) / data->raydir.y;
}

int		raycaster(t_vars *vars, t_data *data, t_param *param, int **map)
{
	int		x;

	x = -1;
	while (++x < param->win_width)
	{
		data->xcam = 2 * x / (double)param->win_width - 1;
		init_vect(data);
		get_sidedist(data);
		dda(data, map);
		get_walldist(data);
		get_stripe(data, param);
		draw_stripe(vars, x);
		get_texture_coor(data);
		texture_map(vars, data, x);
		data->zbuffer[x] = data->perpwalldist;
	}
	draw_sprites(vars, param, data);
	if (vars->save == true)
	{
		data_to_bmp(param, vars->screen);
		exit_program(vars);
	}
	return (0);
}

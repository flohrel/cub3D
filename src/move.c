/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:26:39 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/09 02:33:40 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		worldmap[MAP_WIDTH][MAP_HEIGHT];

void	rotate_left(t_vect *data, t_param *param)
{
	double	oldxdir;
	double	oldxplane;

	oldxdir = data->dir[X];
	oldxplane = data->plane[X];
	data->dir[X] = data->dir[X] * cos(param->rot_speed)
				- data->dir[Y] * sin(param->rot_speed);
	data->dir[Y] = oldxdir * sin(param->rot_speed)
				+ data->dir[Y] * cos(param->rot_speed);
	data->plane[X] = data->plane[X] * cos(param->rot_speed)
				- data->plane[Y] * sin(param->rot_speed);
	data->plane[Y] = oldxplane * sin(param->rot_speed)
				+ data->plane[Y] * cos(param->rot_speed);
}

void	rotate_right(t_vect *data, t_param *param)
{
	double	oldxdir;
	double	oldxplane;

	oldxdir = data->dir[X];
	oldxplane = data->plane[X];
	data->dir[X] = data->dir[X] * cos(-(param->rot_speed))
				- data->dir[Y] * sin(-(param->rot_speed));
	data->dir[Y] = oldxdir * sin(-(param->rot_speed))
				+ data->dir[Y] * cos(-(param->rot_speed));
	data->plane[X] = data->plane[X] * cos(-(param->rot_speed))
				- data->plane[Y] * sin(-(param->rot_speed));
	data->plane[Y] = oldxplane * sin(-(param->rot_speed))
				+ data->plane[Y] * cos(-(param->rot_speed));
}

void	move_forward(t_vect *data, t_param *param)
{
	if (worldmap[(int)(data->pos[X] + data->dir[X] * param->move_speed)]
				[(int)data->pos[Y]] == false)
		data->pos[X] += data->dir[X] * param->move_speed;
	if (worldmap[(int)data->pos[X]]
				[(int)(data->pos[Y] + data->dir[Y] * param->move_speed)] == false)
		data->pos[Y] += data->dir[Y] * param->move_speed;
}

void	move_backward(t_vect *data, t_param *param)
{
	if (worldmap[(int)(data->pos[X] - data->dir[X] * param->move_speed)]
				[(int)data->pos[Y]] == false)
		data->pos[X] -= data->dir[X] * param->move_speed;
	if (worldmap[(int)data->pos[X]]
				[(int)(data->pos[Y] - data->dir[Y] * param->move_speed)] == false)
		data->pos[Y] -= data->dir[Y] * param->move_speed;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:15:30 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/26 17:13:40 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	move_forward(t_vars *vars, t_time *time)
{
	t_data	*data;
	int		**map;
	double	newxpos;
	double	newypos;

	data = vars->data;
	map = vars->param->map;
	newxpos = data->pos.x + data->dir.x * time->move_speed;
	newypos = data->pos.y + data->dir.y * time->move_speed;
	if (map[(int)newxpos][(int)data->pos.y] == false)
		data->pos.x = newxpos;
	if (map[(int)data->pos.x][(int)newypos] == false)
		data->pos.y = newypos;
}

void	move_backward(t_vars *vars, t_time *time)
{
	t_data	*data;
	int		**map;
	double	newxpos;
	double	newypos;

	data = vars->data;
	map = vars->param->map;
	newxpos = data->pos.x - data->dir.x * time->move_speed;
	newypos = data->pos.y - data->dir.y * time->move_speed;
	if (map[(int)newxpos][(int)data->pos.y] == false)
		data->pos.x = newxpos;
	if (map[(int)data->pos.x][(int)newypos] == false)
		data->pos.y = newypos;
}

void	strafe_left(t_vars *vars, t_time *time)
{
	t_data	*data;
	int		**map;
	double	newxpos;
	double	newypos;

	data = vars->data;
	map = vars->param->map;
	newxpos = data->pos.x - data->plane.x * time->move_speed;
	newypos = data->pos.y - data->plane.y * time->move_speed;
	if (map[(int)newxpos][(int)data->pos.y] == false)
		data->pos.x = newxpos;
	if (map[(int)data->pos.x][(int)newypos] == false)
		data->pos.y = newypos;
}

void	strafe_right(t_vars *vars, t_time *time)
{
	t_data	*data;
	int		**map;
	double	newxpos;
	double	newypos;

	data = vars->data;
	map = vars->param->map;
	newxpos = data->pos.x + data->plane.x * time->move_speed;
	newypos = data->pos.y + data->plane.y * time->move_speed;
	if (map[(int)newxpos][(int)data->pos.y] == false)
		data->pos.x = newxpos;
	if (map[(int)data->pos.x][(int)newypos] == false)
		data->pos.y = newypos;
}

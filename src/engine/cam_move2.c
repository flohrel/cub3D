/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:15:30 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/19 13:12:05 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	move_forward(t_vars *vars, t_time *time)
{
	t_data	*data;
	t_param	*param;
	double	newxpos;
	double	newypos;

	data = vars->data;
	param = vars->param;
	newxpos = data->pos.x + data->dir.x * time->move_speed;
	newypos = data->pos.y + data->dir.y * time->move_speed;
	if (vars->map + (int)newxpos * param->map_width
			+ (int)data->pos.y == false)
		data->pos.x = newxpos;
	if (vars->map + (int)data->pos.x * param->map_width
			+ (int)newypos == false)
		data->pos.y = newypos;
}

void	move_backward(t_vars *vars, t_time *time)
{
	t_data	*data;
	t_param	*param;
	double	newxpos;
	double	newypos;

	data = vars->data;
	param = vars->param;
	newxpos = data->pos.x - data->dir.x * time->move_speed;
	newypos = data->pos.y - data->dir.y * time->move_speed;
	if (vars->map + (int)newxpos * param->map_width
			+ (int)data->pos.y == false)
		data->pos.x = newxpos;
	if (vars->map + (int)data->pos.x * param->map_width
			+ (int)newypos == false)
		data->pos.y = newypos;
}

void	strafe_left(t_vars *vars, t_time *time)
{
	t_data	*data;
	t_param	*param;
	double	newxpos;
	double	newypos;

	data = vars->data;
	param = vars->param;
	newxpos = data->pos.x - data->plane.x * time->move_speed;
	newypos = data->pos.y - data->plane.y * time->move_speed;
	if (vars->map + (int)newxpos * param->map_width
			+ (int)data->pos.y == false)
		data->pos.x = newxpos;
	if (vars->map + (int)data->pos.x * param->map_width
			+ (int)newypos == false)
		data->pos.y = newypos;
}

void	strafe_right(t_vars *vars, t_time *time)
{
	t_data	*data;
	t_param	*param;
	double	newxpos;
	double	newypos;

	data = vars->data;
	param = vars->param;
	newxpos = data->pos.x + data->plane.x * time->move_speed;
	newypos = data->pos.y + data->plane.y * time->move_speed;
	if (vars->map + (int)newxpos * param->map_width
			+ (int)data->pos.y == false)
		data->pos.x = newxpos;
	if (vars->map + (int)data->pos.x * param->map_width
			+ (int)newypos == false)
		data->pos.y = newypos;
}

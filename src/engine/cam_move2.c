/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:15:30 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/11 21:44:18 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	move_forward(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	newxpos;
	double	newypos;

	data = vars->data;
	newxpos = data->xpos + data->xdir * time->move_speed;
	newypos = data->ypos + data->ydir * time->move_speed;
	if (g_map[(int)newxpos][(int)data->ypos] == false)
		data->xpos = newxpos;
	if (g_map[(int)data->xpos][(int)newypos] == false)
		data->ypos = newypos;
}

void	move_backward(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	newxpos;
	double	newypos;

	data = vars->data;
	newxpos = data->xpos - data->xdir * time->move_speed;
	newypos = data->ypos - data->ydir * time->move_speed;
	if (g_map[(int)newxpos][(int)data->ypos] == false)
		data->xpos = newxpos;
	if (g_map[(int)data->xpos][(int)newypos] == false)
		data->ypos = newypos;
}

void	strafe_left(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	newxpos;
	double	newypos;

	data = vars->data;
	newxpos = data->xpos - data->xplane * time->move_speed;
	newypos = data->ypos - data->yplane * time->move_speed;
	if (g_map[(int)newxpos][(int)data->ypos] == false)
		data->xpos = newxpos;
	if (g_map[(int)data->xpos][(int)newypos] == false)
		data->ypos = newypos;
}

void	strafe_right(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	newxpos;
	double	newypos;

	data = vars->data;
	newxpos = data->xpos + data->xplane * time->move_speed;
	newypos = data->ypos + data->yplane * time->move_speed;
	if (g_map[(int)newxpos][(int)data->ypos] == false)
		data->xpos = newxpos;
	if (g_map[(int)data->xpos][(int)newypos] == false)
		data->ypos = newypos;
}

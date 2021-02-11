/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:01:47 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/11 21:18:40 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	rotate_left(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	oldxdir;
	double	oldxplane;
	double	xvector;
	double	yvector;

	data = vars->data;
	oldxdir = data->xdir;
	oldxplane = data->xplane;
	xvector = cos(time->rot_speed);
	yvector = sin(time->rot_speed);
	data->xdir = data->xdir * xvector - data->ydir * yvector;
	data->ydir = oldxdir * yvector + data->ydir * xvector;
	data->xplane = data->xplane * xvector - data->yplane * yvector;
	data->yplane = oldxplane * yvector + data->yplane * xvector;
}

void	rotate_right(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	oldxdir;
	double	oldxplane;
	double	xvector;
	double	yvector;

	data = vars->data;
	oldxdir = data->xdir;
	oldxplane = data->xplane;
	xvector = cos(-(time->rot_speed));
	yvector = sin(-(time->rot_speed));
	data->xdir = data->xdir * xvector - data->ydir * yvector;
	data->ydir = oldxdir * yvector + data->ydir * xvector;
	data->xplane = data->xplane * xvector - data->yplane * yvector;
	data->yplane = oldxplane * yvector + data->yplane * xvector;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:01:47 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/12 05:53:37 by flohrel          ###   ########.fr       */
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
	oldxdir = data->dir.x;
	oldxplane = data->plane.x;
	xvector = cos(time->rot_speed);
	yvector = sin(time->rot_speed);
	data->dir.x = data->dir.x * xvector - data->dir.y * yvector;
	data->dir.y = oldxdir * yvector + data->dir.y * xvector;
	data->plane.x = data->plane.x * xvector - data->plane.y * yvector;
	data->plane.y = oldxplane * yvector + data->plane.y * xvector;
}

void	rotate_right(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	oldxdir;
	double	oldxplane;
	double	xvector;
	double	yvector;

	data = vars->data;
	oldxdir = data->dir.x;
	oldxplane = data->plane.x;
	xvector = cos(-(time->rot_speed));
	yvector = sin(-(time->rot_speed));
	data->dir.x = data->dir.x * xvector - data->dir.y * yvector;
	data->dir.y = oldxdir * yvector + data->dir.y * xvector;
	data->plane.x = data->plane.x * xvector - data->plane.y * yvector;
	data->plane.y = oldxplane * yvector + data->plane.y * xvector;
}

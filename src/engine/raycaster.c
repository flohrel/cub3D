/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:35:07 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/14 02:51:29 by flohrel          ###   ########.fr       */
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

void	dda(t_data *data)
{
	int hit;
	
	hit = 0;
	while (hit == 0)
	{
		if (data->sidedist.x < data->sidedist.y)
		{
			data->sidedist.x += data->deltadist.x;
			data->map.x += data->step.x;
			data->side = 0;
		}
		else
		{
			data->sidedist.y += data->deltadist.y;
			data->map.y += data->step.y;
			data->side = 1;
		}
		if (g_map[data->map.x][data->map.y] > 0)
			hit = 1;
	}
}

void	get_walldist(t_data *data)
{
	if (data->side == 0)
		data->perpwalldist = (data->map.x - data->pos.x
			+ (1 - data->step.x) / 2) / data->raydir.x;
	else
		data->perpwalldist = (data->map.y - data->pos.y
			+ (1 - data->step.y) / 2) / data->raydir.y;
}

int		raycaster(t_vars *vars, t_data *data)
{
	int		x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		data->xcam = 2 * x / (double)WIN_WIDTH - 1;
		init_vect(data);
		get_sidedist(data);
		dda(data);
		get_walldist(data);
		//Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / data->perpwalldist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
		int color;
		switch(g_map[data->map.x][data->map.y])
		{
			case 1:  color = RED;  break;
			case 2:  color = GREEN;  break;
			case 3:  color = BLUE;   break;
			case 4:  color = WHITE;  break;
			default: color = YELLOW; break;
		}
		//give x and y sides different brightness
		if (data->side == 1)
			color = color / 2;
		//draw the pixels of the stripe as a vertical line
		vertical_line(vars->img, x, drawStart, drawEnd, color);
	}
	return (0);
}

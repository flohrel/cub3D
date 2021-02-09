/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:35:07 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/09 02:34:03 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	worldmap[MAP_WIDTH][MAP_HEIGHT]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	vertical_line(t_img *img, int x, int ymin, int ymax, int color)
{
	int	y;

	y = ymin;
	while (y <= ymax)
	{
		img_pixel_put(img, x, y, color);
		y++;
	}
}

void	init_data(t_vect *data, t_time *time, t_param *param)
{
	data->pos[X] = 22;
	data->pos[Y] = 12;
	data->dir[X] = -1;
	data->dir[Y] = 0;
	data->plane[X] = 0;
	data->plane[Y] = 0.66;
	time->time = 0;
	time->old_time = 0;
	param->move_speed = time->frame_time * 50.0;
	param->rot_speed = time->frame_time * 30.0;
}

void	get_direction(t_vect *data, int x)
{
	data->xcam = (2 * x) / (double)WIN_WIDTH - 1;
	data->raydir[X] = data->dir[X] + data->plane[X] * data->xcam;
	data->raydir[Y] = data->dir[Y] + data->plane[Y] * data->xcam;
	data->deltadist[X] = fabs(1 / data->raydir[X]);
	data->deltadist[Y] = fabs(1 / data->raydir[Y]);
	if (data->raydir[X] < 0)
	{
		data->step[X] = -1;
		data->sidedist[X] = (data->pos[X] - data->map[X]) * data->deltadist[X];
	}
	else
	{
		data->step[X] = 1;
		data->sidedist[X] = (data->map[X] + 1.0 - data->pos[X]) * data->deltadist[X];
	}
	if (data->raydir[Y] < 0)
	{
		data->step[Y] = -1;
		data->sidedist[Y] = (data->pos[Y] - data->map[Y]) * data->deltadist[Y];
	}
	else
	{
		data->step[Y] = 1;
		data->sidedist[Y] = (data->map[Y] + 1.0 - data->pos[Y]) * data->deltadist[Y];
	}
}

int		raycaster(t_vars *vars, t_vect *data)
{
	int		x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		get_direction(data, x);
		//which box of the map we're in
		data->map[X] = (int)data->pos[X];
		data->map[Y] = (int)data->pos[Y];

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (data->sidedist[X] < data->sidedist[Y])
			{
				data->sidedist[X] += data->deltadist[X];
				data->map[X] += data->step[X];
				side = 0;
			}
			else
			{
				data->sidedist[Y] += data->deltadist[Y];
				data->map[Y] += data->step[Y];
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldmap[data->map[X]][data->map[Y]] > 0)
				hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			data->perpdist = (data->map[X] - data->pos[X]
							+ (1 - data->step[X]) / 2) / data->raydir[X];
		else
			data->perpdist = (data->map[Y] - data->pos[Y] + (1 - data->step[Y]) / 2) / data->raydir[Y];

		//Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / data->perpdist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		int color;
		switch (worldmap[data->map[X]][data->map[Y]])
		{
			case 1:  color = FIREBRICK;  break;
			case 2:  color = DRED;  break;
			case 3:  color = INDIGO;   break;
			case 4:  color = TEAL;  break;
			default: color = YELLOW; break;
		}

		//give x and y sides different brightness
		if (side == 1)
			color = color / 2;

		//draw the pixels of the stripe as a vertical line
		vertical_line(vars->img, x, drawStart, drawEnd, color);
		x++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:35:07 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/07 00:58:35 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MAP_WIDTH	24
#define MAP_HEIGHT	24

int	worldMap[MAP_WIDTH][MAP_HEIGHT]=
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

void	rotate_left(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	oldxdir;
	double	oldxplane;

	data = vars->data;
	oldxdir = data->xdir;
	oldxplane = data->xplane;
	data->xdir = data->xdir * cos(time->rot_speed) - data->ydir * sin(time->rot_speed);
	data->ydir = oldxdir * sin(time->rot_speed) + data->ydir * cos(time->rot_speed);
	data->xplane = data->xplane * cos(time->rot_speed) - data->yplane * sin(time->rot_speed);
	data->yplane = oldxplane * sin(time->rot_speed) + data->yplane * cos(time->rot_speed);
}

void	rotate_right(t_vars *vars, t_time *time)
{
	t_data	*data;
	double	oldxdir;
	double	oldxplane;

	data = vars->data;
	oldxdir = data->xdir;
	oldxplane = data->xplane;
	data->xdir = data->xdir * cos(-(time->rot_speed)) - data->ydir * sin(-(time->rot_speed));
	data->ydir = oldxdir * sin(-(time->rot_speed)) + data->ydir * cos(-(time->rot_speed));
	data->xplane = data->xplane * cos(-(time->rot_speed)) - data->yplane * sin(-(time->rot_speed));
	data->yplane = oldxplane * sin(-(time->rot_speed)) + data->yplane * cos(-(time->rot_speed));
}

void	move_forward(t_vars *vars, t_time *time)
{
	t_data	*data;

	data = vars->data;
	if (worldMap[(int)(data->xpos + data->xdir * time->move_speed)][(int)data->ypos] == false)
		data->xpos += data->xdir * time->move_speed;
	if (worldMap[(int)data->xpos][(int)(data->ypos + data->ydir * time->move_speed)] == false)
		data->ypos += data->ydir * time->move_speed;
}

void	move_backward(t_vars *vars, t_time *time)
{
	t_data	*data;
	
	data = vars->data;
	if (worldMap[(int)(data->xpos - data->xdir * time->move_speed)][(int)data->ypos] == false)
		data->xpos -= data->xdir * time->move_speed;
	if (worldMap[(int)data->xpos][(int)(data->ypos - data->ydir * time->move_speed)] == false)
		data->ypos -= data->ydir * time->move_speed;
}

void	vertical_line(t_img *img, int x, int drawStart, int drawEnd, int color)
{
	int	y;

	y = drawStart;
	while (y < drawEnd)
	{
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

int		raycaster(t_vars *vars, t_data *data)
{
	int		x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		data->xcam = 2 * x / (double)WIN_WIDTH - 1;
		data->xraydir = data->xdir + data->xplane * data->xcam;
		data->yraydir = data->ydir + data->yplane * data->xcam;
		//which box of the map we're in
		int mapX = (int)data->xpos;
		int mapY = (int)data->ypos;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double perpWallDist;
		double deltaDistX = (data->yraydir == 0) ? 0 : ((data->xraydir == 0) ? 1 : abs(1 / data->xraydir));
		double deltaDistY = (data->xraydir == 0) ? 0 : ((data->yraydir == 0) ? 1 : abs(1 / data->yraydir));

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (data->xraydir < 0)
		{
			stepX = -1;
			sideDistX = (data->xpos - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->xpos) * deltaDistX;
		}
		if (data->yraydir < 0)
		{
			stepY = -1;
			sideDistY = (data->ypos - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->ypos) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (mapX - data->xpos + (1 - stepX) / 2) / data->xraydir;
		else
			perpWallDist = (mapY - data->ypos + (1 - stepY) / 2) / data->yraydir;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		int color;
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = RED;  break;
			case 2:  color = GREEN;  break;
			case 3:  color = BLUE;   break;
			case 4:  color = WHITE;  break;
			default: color = YELLOW; break;
		}

		//give x and y sides different brightness
		if (side == 1)
			color = color / 2;

		//draw the pixels of the stripe as a vertical line
		vertical_line(vars->img, x, drawStart, drawEnd, color);
	}
	return (0);
}

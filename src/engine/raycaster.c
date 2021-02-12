/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:35:07 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/12 05:57:20 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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
		data->raydir.x = data->dir.x + data->plane.x * data->xcam;
		data->raydir.y = data->dir.y + data->plane.y * data->xcam;

		//which box of the map we're in
		int mapX = (int)data->pos.x;
		int mapY = (int)data->pos.y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double perpWallDist;
		double deltaDistX = fabs(1 / data->raydir.x);
		double deltaDistY = fabs(1 / data->raydir.y);

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (data->raydir.x < 0)
		{
			stepX = -1;
			sideDistX = (data->pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->pos.x) * deltaDistX;
		}
		if (data->raydir.y < 0)
		{
			stepY = -1;
			sideDistY = (data->pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->pos.y) * deltaDistY;
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
			if (g_map[mapX][mapY] > 0)
				hit = 1;
		}

		//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side == 0)
			perpWallDist = (mapX - data->pos.x + (1 - stepX) / 2) / data->raydir.x;
		else
			perpWallDist = (mapY - data->pos.y + (1 - stepY) / 2) / data->raydir.y;

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
		switch(g_map[mapX][mapY])
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
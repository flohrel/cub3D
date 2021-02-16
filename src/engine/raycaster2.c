/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:30:55 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/16 15:39:25 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	vertical_line(t_img *img, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

void	get_stripe(t_data *data)
{
	int stripelen;
	
	stripelen = (int)(WIN_HEIGHT / data->perpwalldist);
	data->pixeltop = -stripelen / 2 + WIN_HEIGHT / 2;
	if (data->pixeltop < 0)
		data->pixeltop = 0;
	data->pixelbot = stripelen / 2 + WIN_HEIGHT / 2;
	if (data->pixelbot >= WIN_HEIGHT)
		data->pixelbot = WIN_HEIGHT - 1;
}

void	get_fps(t_vars *vars, t_time *time)
{
	char	*fps;

	time->old_time = time->time;
	time->time = clock();
	time->frame_time = (time->time - time->old_time) / CLOCKS_PER_SEC;
	fps = ft_itoa(1 / time->frame_time);
	mlx_string_put(vars->mlx, vars->win, 15, 15, 0xFFFFFFFF, fps);
	time->move_speed = time->frame_time * 10.0;
	time->rot_speed = time->frame_time * 5.0;
	free(fps);
}

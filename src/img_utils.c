/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:04:46 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/11 19:04:59 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "img_utils.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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

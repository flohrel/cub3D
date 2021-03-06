/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:30:55 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 20:09:11 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_stripe(t_vars *vars, int x)
{
	int		y;
	t_data	*data;
	t_param	*param;

	data = vars->data;
	param = vars->param;
	y = 0;
	while (y < data->pixelbot)
	{
		my_mlx_pixel_put(vars->screen, x, y, param->ceil_color);
		y++;
	}
	y = data->pixeltop;
	while (y < param->win_height)
	{
		my_mlx_pixel_put(vars->screen, x, y, param->floor_color);
		y++;
	}
}

void	get_stripe(t_data *data, t_param *param)
{
	data->stripe_len = (int)(param->win_height / data->perpwalldist);
	data->pixeltop = -data->stripe_len / 2 + param->win_height / 2;
	if (data->pixeltop < 0)
		data->pixeltop = 0;
	data->pixelbot = data->stripe_len / 2 + param->win_height / 2;
	if (data->pixelbot >= param->win_height)
		data->pixelbot = param->win_height - 1;
}

void	get_texture_coor(t_data *data)
{
	data->tex_id = data->side;
	if (data->side < 2)
		data->xwall = data->pos.y + data->perpwalldist * data->raydir.y;
	else
		data->xwall = data->pos.x + data->perpwalldist * data->raydir.x;
	data->xwall -= floor(data->xwall);
	data->tex.x = (int)(data->xwall * (double)TEX_WIDTH);
	if (((data->side < 2) && (data->raydir.x > 0)) ||
		((data->side > 1) && (data->raydir.y < 0)))
		data->tex.x = TEX_WIDTH - data->tex.x - 1;
}

void	texture_map(t_vars *vars, t_data *data, int x)
{
	double		step;
	double		texpos;
	uint32_t	color;
	t_img		*texture;
	int			y;

	step = 1.0 * TEX_HEIGHT / data->stripe_len;
	texpos = (data->pixeltop - vars->param->win_height / 2
			+ data->stripe_len / 2) * step;
	y = data->pixeltop;
	texture = &vars->textures[data->tex_id];
	while (y < data->pixelbot)
	{
		data->tex.y = (int)texpos & (TEX_HEIGHT - 1);
		texpos += step;
		color = *(uint32_t *)(texture->addr + (texture->line_length *
				data->tex.y + data->tex.x * (texture->bits_per_pixel / 8)));
		my_mlx_pixel_put(vars->screen, x, y, color);
		y++;
	}
}

void	get_fps(t_time *time)
{
	time->old_time = time->time;
	time->time = clock();
	time->frame_time = (time->time - time->old_time) / CLOCKS_PER_SEC;
	time->move_speed = time->frame_time * 10.0;
	time->rot_speed = time->frame_time * 5.0;
}

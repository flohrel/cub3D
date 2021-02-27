/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:30:55 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/26 17:31:08 by flohrel          ###   ########.fr       */
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

void	get_texture_coor(t_data *data, int **map)
{
	data->tex_id = map[data->map.y][data->map.x] - 1;
	if (data->side == 0)
		data->xwall = data->pos.y + data->perpwalldist * data->raydir.y;
	else
		data->xwall = data->pos.x + data->perpwalldist * data->raydir.x;
	data->xwall -= floor((data->xwall));
	data->tex.x = (int)(data->xwall * (double)TEX_WIDTH);
	if (((data->side == 0) && (data->raydir.x > 0)) ||
		((data->side == 1) && (data->raydir.x < 0)))
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
	while (y < data->pixelbot)
	{
		data->tex.y = (int)texpos & (TEX_HEIGHT - 1);
		texpos += step;
		texture = &vars->textures[data->tex_id];
		color = *(uint32_t *)(texture->image + TEX_HEIGHT * data->tex.y + data->tex.x);
		if (data->side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(vars->screen, x, y, color);
		y++;
	}
}

void	get_fps(t_vars *vars, t_time *time)
{
	char	*fps;

	time->old_time = time->time;
	time->time = clock();
	time->frame_time = (time->time - time->old_time) / CLOCKS_PER_SEC;
	fps = ft_itoa(1 / time->frame_time);
	mlx_string_put(vars->mlx, vars->win, 15, 15, WHITE, fps);
	time->move_speed = time->frame_time * 10.0;
	time->rot_speed = time->frame_time * 5.0;
	free(fps);
}

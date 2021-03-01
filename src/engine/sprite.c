/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:44:48 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 02:59:46 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	get_sprite_dist(t_vars *vars, t_data *data)
{
	t_list		*sprites;
	t_sprite	*sprite;

	sprites = vars->sprites;
	while (sprites != NULL)
	{
		sprite = (t_sprite *)sprites->content;
		sprite->distance = ((data->pos.x - sprite->pos.x)
				* (data->pos.x - sprite->pos.x)
				+ (data->pos.y - sprite->pos.y)
				* (data->pos.y - sprite->pos.y));
		sprites = sprites->next;
	}
	sort_sprites(&vars->sprites);
}

void	init_sprite_vars(t_param *param, t_data *data, t_sprite *sprite)
{
	sprite->pos2.x = sprite->pos.x - data->pos.x;
	sprite->pos2.y = sprite->pos.y - data->pos.y;
	sprite->invdet = 1.0 / (data->plane.x * data->dir.y
			- data->dir.x * data->plane.y);
	sprite->transform.x = sprite->invdet * (data->dir.y
			* sprite->pos2.x - data->dir.x * sprite->pos2.y);
	sprite->transform.y = sprite->invdet * (-data->plane.y
			* sprite->pos2.x + data->plane.x * sprite->pos2.y);
	sprite->screenx = (int)((param->win_width / 2)
			* (1 + sprite->transform.x / sprite->transform.y));
	sprite->height = abs((int)(param->win_height / (sprite->transform.y)));
	sprite->draw_start.y = -sprite->height / 2 + param->win_height / 2;
	if (sprite->draw_start.y < 0)
		sprite->draw_start.y = 0;
	sprite->draw_end.y = sprite->height / 2 + param->win_height / 2;
	if (sprite->draw_end.y >= param->win_height)
		  sprite->draw_end.y = param->win_height - 1;
	sprite->width = abs((int)(param->win_height / (sprite->transform.y)));
	sprite->draw_start.x = -sprite->width / 2 + sprite->screenx;
	if (sprite->draw_start.x < 0)
		  sprite->draw_start.x = 0;
	sprite->draw_end.x = sprite->width / 2 + sprite->screenx;
	if (sprite->draw_end.x >= param->win_width)
		sprite->draw_end.x = param->win_width - 1;
}

void	sprite_to_screen2(t_vars *vars, t_param *param, t_sprite *sprite, int x)
{
	int			d;
	int			y;
	uint32_t	color;
	t_img		*texture;
	
	y = sprite->draw_start.y;
	texture = &vars->textures[4];
	while (y < sprite->draw_end.y)
	{
		d = (y) * 256 - param->win_height * 128 + sprite->height * 128;
		sprite->tex.y = ((d * TEX_HEIGHT) / sprite->height) / 256;
		color = *(uint32_t *)(texture->addr
				+ texture->line_length * sprite->tex.y
				+ sprite->tex.x * (texture->bits_per_pixel / 8));
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(vars->screen, x, y, color);
		y++;
	}
}

void	sprite_to_screen(t_vars *vars, t_param *param, t_sprite *sprite)
{
	int		stripe;

	stripe = sprite->draw_start.x;
	while (stripe < sprite->draw_end.x)
	{
		sprite->tex.x = (int)(256 * (stripe - (-sprite->width / 2
						+ sprite->screenx)) * TEX_WIDTH / sprite->width) / 256;
		if ((sprite->transform.y > 0) && (stripe > 0) &&
				(stripe < param->win_width) &&
				(sprite->transform.y < vars->data->zbuffer[stripe]))
			sprite_to_screen2(vars, param, sprite, stripe);
		stripe++;
	}
}

void	draw_sprites(t_vars *vars, t_param *param, t_data *data)
{
	t_list		*sprites;
	t_sprite	*sprite;

	get_sprite_dist(vars, data);
	sprites = vars->sprites;
	while (sprites != NULL)
	{
		sprite = (t_sprite *)sprites->content;
		init_sprite_vars(param, data, sprite);
		sprite_to_screen(vars, param, sprite);
		sprites = sprites->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:04:46 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/06 19:21:51 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "draw_2d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_img *img, int xpos, int ypos, int radius)
{
	int		x;
	int		y;
	float	radiant;

	y = 0;
	x = 0;
	radiant = 0;
	while (radiant < (2 * M_PI))
	{
		y = sin(radiant) * radius;
		x = cos(radiant) * radius;
		my_mlx_pixel_put(img, xpos + x, ypos + y, RED);
		radiant += 0.1;
	}
}

void	draw_semicircle(t_img *img, int xpos, int ypos, int radius, int color)
{
	int		x;
	int		y;
	float	radiant;

	y = 0;
	x = 0;
	radiant = M_PI;
	while (radiant < (2 * M_PI))
	{
		y = sin(radiant) * radius;
		x = cos(radiant) * radius;
		my_mlx_pixel_put(img, xpos + x, ypos + y, color);
		radiant += 0.001;
	}
}

void	draw_square(t_img *img, int xpos, int ypos, int size)
{
	int		x;
	int		y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (!y || ((y + 1) == size) || !x || ((x + 1) == size))
				my_mlx_pixel_put(img, xpos + x, ypos + y, BLUE);
		}
	}
}

void	draw_rainbow(t_img *img, int x, int y, int mod)
{
	int		i;
	int		j;
	int		rainbow_colors[7] = { RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET };

	j = -1;
	while (++j < 7)
	{
		i = -1;
		while (++i < 10)
			draw_semicircle(img, x, y, ((y - (20 * j)) / 2) - i, rainbow_colors[(j + mod) % 7]);
	}
}

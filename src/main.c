/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/01 17:22:02 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		rainbow_colors[7] = { RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET };

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_data *data, int xpos, int ypos, int radius)
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
		my_mlx_pixel_put(data, xpos + x, ypos + y, RED);
		radiant += 0.1;
	}
}

void	draw_semicircle(t_data *data, int xpos, int ypos, int radius, int color)
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
		my_mlx_pixel_put(data, xpos + x, ypos + y, color);
		radiant += 0.001;
	}
}

void	draw_square(t_data *data, int xpos, int ypos, int size)
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
				my_mlx_pixel_put(data, xpos + x, ypos + y, BLUE);
		}
	}
}

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		i;
	int		j;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_HEIGHT, WIN_WIDTH, "TEST");
	img.img = mlx_new_image(mlx, WIN_HEIGHT, WIN_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
//	draw_circle(&img, 42, 42, 42);
//	draw_square(&img, 128, 128, 42);

	x = 390;
	y = 400;
	j = -1;
	while (++j < 7)
	{
		i = -1;
		while (++i < 10)
			draw_semicircle(&img, x, y, x - i, rainbow_colors[j]);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_key_hook(mlx_win, exit_key, (void *)0);
	mlx_loop(mlx);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/04 17:49:00 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		keybind(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int		main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIN_HEIGHT, WIN_WIDTH, "TEST");
	img.img = mlx_new_image(vars.mlx, WIN_HEIGHT, WIN_WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_rainbow(&img, 400, 400);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, keybind, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

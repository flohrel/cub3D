/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/04 23:25:18 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_img(t_data *img)
{
	if (img->img)
		free(img->img);
}

int		free_all(t_vars *vars)
{
	free_img(vars->img);
	free(vars->mlx);
	return (-1);
}

int		keybind(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_all(vars);
		exit(0);
	}
	if (keycode == SPACE)
		vars->mod++;
	return (0);
}

int		init_image(t_vars *vars, t_data *img)
{
	vars->img = img;
	img->img = mlx_new_image(vars->mlx, WIN_HEIGHT, WIN_WIDTH);
	if (!img->img)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (-1);
	return (0);
}

int		init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (-1);
	vars->win = mlx_new_window(vars->mlx, WIN_HEIGHT, WIN_WIDTH, "TEST");
	if (!vars->win)
	{
		free(vars->mlx);
		return (-1);
	}
	return (0);
}

int		render_next_frame(t_vars *vars)
{
	draw_rainbow(vars->img, 400, 400, vars->mod);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int		main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mod = 0;
	if (init_window(&vars) == -1 ||
		init_image(&vars, &img) == -1)
		return (free_all(&vars));
	mlx_key_hook(vars.win, keybind, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

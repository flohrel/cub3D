/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/12 05:41:59 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_program(t_vars *vars)
{
	if (vars->img)
		mlx_destroy_image(vars->mlx, vars->img->image);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int		keybind(int keycode, t_vars *vars)
{
	if (keycode == ESCAPE)
		exit_program(vars);
	if (keycode == TURN_LEFT)
		rotate_left(vars, vars->time);
	if (keycode == TURN_RIGHT)
		rotate_right(vars, vars->time);
	if (keycode == FORWARD)
		move_forward(vars, vars->time);
	if (keycode == BACKWARD)
		move_backward(vars, vars->time);
	if (keycode == LEFT)
		strafe_left(vars, vars->time);
	if (keycode == RIGHT)
		strafe_right(vars, vars->time);
	return (0);
}

int		init_image(t_vars *vars, t_img *img)
{
	img->image = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!img->image)
		return (-1);
	img->addr = mlx_get_data_addr(img->image, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (-1);
	return (0);
}

int		init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit(-1);
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "TEST");
	if (!vars->win)
	{
		exit_program(vars);
		return (-1);
	}
	return (0);
}

void	init_data(t_data *data, t_time *time)
{
	data->pos.x = 22;
	data->pos.y = 12;
	data->xdir = -1;
	data->ydir = 0;
	data->xplane = 0;
	data->yplane = 0.66;
	time->time = 0;
	time->old_time = 0;
}

int		render_next_frame(t_vars *vars)
{
	ft_bzero(vars->img->addr, vars->img->line_length * WIN_HEIGHT);
	raycaster(vars, vars->data);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->image, 0, 0);
	get_fps(vars, vars->time);
	return (0);
}

int		main(void)
{
	t_vars	vars;
	t_img	img;
	t_data	data;
	t_time	time;

	vars.img = &img;
	vars.data = &data;
	vars.time = &time;
	if (init_window(&vars) == -1 ||
		init_image(&vars, &img) == -1)
		return (exit_program(&vars));
	init_data(vars.data, vars.time);
	mlx_hook(vars.win, 2, (1L << 0), keybind, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

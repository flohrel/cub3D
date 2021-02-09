/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/09 02:46:21 by flohrel          ###   ########.fr       */
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
	if (keycode == LEFT)
		rotate_left(vars, vars->time);
	if (keycode == RIGHT)
		rotate_right(vars, vars->time);
	if (keycode == FORWARD)
		move_forward(vars, vars->time);
	if (keycode == BACKWARD)
		move_backward(vars, vars->time);
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
	data->xpos = 22;
	data->ypos = 12;
	data->xdir = -1;
	data->ydir = 0;
	data->xplane = 0;
	data->yplane = 0.66;
	time->time = 0;
	time->old_time = 0;
}

void	get_fps(t_vars *vars, t_time *time)
{
	char	*fps;

	time->old_time = time->time;
	time->time = clock();
	time->frame_time = (time->time - time->old_time) / CLOCKS_PER_SEC;
	fps = ft_itoa(1 / time->frame_time);
	mlx_string_put(vars->mlx, vars->win, 15, 15, WHITE, fps);
	time->move_speed = time->frame_time * 50.0;
	time->rot_speed = time->frame_time * 30.0;
	free(fps);
}

int		render_next_frame(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->image);
	init_image(vars, vars->img);
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

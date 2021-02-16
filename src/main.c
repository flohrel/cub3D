/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/16 16:21:40 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		new_window(t_vars *vars)
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

int		init_data(t_vars *vars, t_data *data, t_time *time)
{
	data->pos.x = 22;
	data->pos.y = 12;
	data->dir.x = -1;
	data->dir.y = 0;
	data->plane.x = 0;
	data->plane.y = 0.66;
	time->time = 0;
	time->old_time = 0;
	vars->kbflags = 0;
	vars->textures = NULL;
	return (SUCCESS);
}

void	get_input(t_vars *vars, t_time *time, int kbflags)
{
	if (check_flag(kbflags, ESC))
		exit_program(vars);
	if (check_flag(kbflags, TL))
		rotate_left(vars, time);
	if (check_flag(kbflags, TR))
		rotate_right(vars, time);
	if (check_flag(kbflags, BW))
		move_backward(vars, time);
	if (check_flag(kbflags, FW))
		move_forward(vars, time);
	if (check_flag(kbflags, R))
		strafe_right(vars, time);
	if (check_flag(kbflags, L))
		strafe_left(vars, time);
}

int		render_next_frame(t_vars *vars)
{
	t_img	*img;

	img = vars->img;
	ft_bzero(img->addr, img->line_length * WIN_HEIGHT);
	raycaster(vars, vars->data);
	get_input(vars, vars->time, vars->kbflags);
	mlx_put_image_to_window(vars->mlx, vars->win, img->image, 0, 0);
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
	if (new_window(&vars) == -1 ||
		new_screen(&vars, &img, WIN_WIDTH, WIN_HEIGHT) == -1 ||
		init_data(&vars, vars.data, vars.time) == -1 ||
		load_textures(&vars) == -1)
		return (exit_program(&vars));
	printf("ici");
	mlx_hook(vars.win, 2, (1L << 0), key_press, &(vars.kbflags));
	mlx_hook(vars.win, 3, (1L << 1), key_release, &(vars.kbflags));
	mlx_hook(vars.win, EXIT_EVENT, EXIT_WIN_MASK, exit_program, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

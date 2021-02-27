/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:47:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/27 17:51:00 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		new_window(t_vars *vars)
{
	t_param	*param;

	param = vars->param;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		exit_program(vars);
	get_screen_size(vars, vars->param);
	vars->win = mlx_new_window(vars->mlx, param->win_width,
		param->win_height, "cub3D");
	if (!vars->win)
	{
		exit_program(vars);
		return (-1);
	}
	return (0);
}

void	init_data(t_vars *vars, t_param* param, t_data *data, t_time *time)
{
	data->pos.x = param->map_width - param->pos.x - 1;
	data->pos.y = param->pos.y;
	time->time = 0;
	time->old_time = 0;
	vars->kbflags = 0;
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
	if (check_flag(kbflags, RT))
		strafe_right(vars, time);
	if (check_flag(kbflags, LT))
		strafe_left(vars, time);
}

int		render_next_frame(t_vars *vars)
{
	t_img	*screen;

	screen = vars->screen;
	ft_bzero(screen->addr, screen->line_length * vars->param->win_height);
	raycaster(vars, vars->data, vars->param, vars->param->map);
	get_input(vars, vars->time, vars->kbflags);
	mlx_put_image_to_window(vars->mlx, vars->win, screen->image, 0, 0);
	get_fps(vars, vars->time);
	return (0);
}

void	init_vars(t_vars *vars, t_param *param)
{
	int		i;

	errno = 0;
	param->save = false;
	i = -1;
	while (++i < 5)
	{
		param->texture_path[i] = NULL;
		vars->textures[i].image = NULL;
	}
	param->map_height = 0;
	param->map_width = 0;
	vars->win = NULL;
	vars->mlx = NULL;
}

int		main(int ac, char **av)
{
	t_vars	vars;
	t_img	screen;
	t_data	data;
	t_time	time;
	t_param	param;

	vars.screen = &screen;
	vars.data = &data;
	vars.time = &time;
	vars.param = &param;
	init_vars(&vars, &param);
	if (parser(&vars, ac, av) == -1 ||
		new_window(&vars) == -1 ||
		new_screen(&vars, &screen, param.win_width, param.win_height) == -1 ||
		load_texture(&vars, &param) == -1)
		return (exit_program(&vars));
	init_data(&vars, vars.param, vars.data, vars.time);
	mlx_hook(vars.win, 2, (1L << 0), key_press, &(vars.kbflags));
	mlx_hook(vars.win, 3, (1L << 1), key_release, &(vars.kbflags));
	mlx_hook(vars.win, EXIT_EVENT, EXIT_WIN_MASK, exit_program, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

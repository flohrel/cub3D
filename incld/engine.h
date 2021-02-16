/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:02:46 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/16 15:38:47 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <math.h>
# include <stdbool.h>
# include "data.h"
# include "utils/color.h"
# include "utils/image.h"

# define MAP_WIDTH	24
# define MAP_HEIGHT	24

/*
**		raycaster.c
*/
int		raycaster(t_vars *vars, t_data *data);

/*
**		raycaster2.c
*/
void	vertical_line(t_img *img, int x, int drawStart, int drawEnd, int color);
void	get_stripe(t_data *data);
void	get_fps(t_vars *vars, t_time *time);

/*
**		cam_move.c
*/
void	rotate_right(t_vars *vars, t_time *time);
void	rotate_left(t_vars *vars, t_time *time);

/*
**		cam_move2.c
*/
void	move_backward(t_vars *vars, t_time *time);
void	move_forward(t_vars *vars, t_time *time);
void	strafe_right(t_vars *vars, t_time *time);
void	strafe_left(t_vars *vars, t_time *time);

extern int	g_map[MAP_WIDTH][MAP_HEIGHT];

#endif

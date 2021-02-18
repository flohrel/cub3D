/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:02:46 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 17:23:12 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <math.h>
# include <stdbool.h>
# include <stdint.h>
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
void	get_stripe(t_data *data);
void	get_texture_coor(t_data *data);
void	texture_map(t_vars *vars, t_data *data, int x);
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

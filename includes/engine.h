/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:29:12 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/09 02:34:12 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <math.h>
# include "cub3d.h"
# include "data.h"

# define MAP_WIDTH	24
# define MAP_HEIGHT	24

int		raycaster(t_vars *vars, t_vect *data);
void	init_data(t_vect *data, t_time *time, t_param *param);

/*
**		move.c
*/
void	move_backward(t_vect *data, t_param *param);
void	move_forward(t_vect *data, t_param *param);
void	rotate_right(t_vect *data, t_param *param);
void	rotate_left(t_vect *data, t_param *param);

extern int	worldmap[MAP_WIDTH][MAP_HEIGHT];

#endif

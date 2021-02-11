/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:55:55 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/11 17:18:19 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <time.h>
# include <stdbool.h>
# include "mlx.h"
# include "libft.h"
# include "color.h"
# include "math.h"
# include "data_struct.h"
# include "img_utils.h"
# include "keycode.h"

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT	600
# endif

# ifndef WIN_WIDTH
#  define WIN_WIDTH		800
# endif

int		raycaster(t_vars *vars, t_data *data);
void	move_backward(t_vars *vars, t_time *time);
void	move_forward(t_vars *vars, t_time *time);
void	rotate_right(t_vars *vars, t_time *time);
void	rotate_left(t_vars *vars, t_time *time);

#endif

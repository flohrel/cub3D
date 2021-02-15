/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:55:55 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/15 14:37:00 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <time.h>
# include <stdbool.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"
# include "color.h"
# include "math.h"
# include "data_type.h"
# include "img_utils.h"
# include "engine.h"
# include "keycode.h"
# include "hook.h"
# include "flag.h"

# ifdef __linux__
#  define EXIT_EVENT	33
#  define EXIT_WIN_MASK	(1L << 5)
# elif __APPLE__
#  define EXIT_EVENT	17
#  define EXIT_WIN_MASK	(1L << 17)
# endif

int		exit_program(t_vars *vars);

#endif

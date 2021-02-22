/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:55:55 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/22 15:38:28 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>

/*
**		platform dependant
*/
# ifdef __linux__
#  include "platform/linux.h"
# elif __APPLE__
#  include "platform/mac.h"
# endif

/*
**		general
*/
# include "mlx.h"
# include "libft.h"
# include "data.h"
# include "parse.h"

/*
**		engine
*/
# include "engine.h"
# include "hook.h"

/*
**		utils
*/
# include "utils/flag.h"
# include "utils/keycode.h"
# include "utils/color.h"
# include "utils/image.h"

# define ERROR		-1
# define SUCCESS	0

#endif

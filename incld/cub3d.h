/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:55:55 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/16 15:48:16 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <time.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "data.h"

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

# ifdef __linux__
#  include "platform/linux.h"
# elif __APPLE__
#  include "platform/mac.h"
# endif

# define ERROR		-1
# define SUCCESS	0

#endif

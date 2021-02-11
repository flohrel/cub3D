/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:08:58 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/11 17:19:16 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_UTILS_H
# define IMG_UTILS_H

# include <time.h>
# include "mlx.h"
# include "data_struct.h"
# include "color.h"
# include "libft.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	get_fps(t_vars *vars, t_time *time);

# endif

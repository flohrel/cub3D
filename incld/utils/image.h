/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:08:58 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 19:39:50 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_UTILS_H
# define IMG_UTILS_H

# include "cub3d.h"

# define TEX_WIDTH	64
# define TEX_HEIGHT	64

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		xpm_to_img(t_vars *vars, t_img **textures, char *filename);
int		load_texture(t_vars *vars, t_param *param);
int		new_screen(t_vars *vars, t_img *img, int width, int height);

# endif

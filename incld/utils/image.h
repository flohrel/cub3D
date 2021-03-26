/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:08:58 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 20:08:14 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "cub3d.h"

# define TEX_WIDTH	256
# define TEX_HEIGHT	256

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		xpm_to_img(t_vars *vars, t_img *texture, char *filename);
int		load_texture(t_vars *vars, t_param *param);
int		new_screen(t_vars *vars, t_img *img, int width, int height);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:08:58 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/16 17:09:34 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_UTILS_H
# define IMG_UTILS_H

# include "cub3d.h"

# define TEX_WIDTH	64
# define TEX_HEIGHT	64

# define MLX_TEX0	"rsrc/textures/gray_wall.xpm"
# define MLX_TEX1	"rsrc/textures/wall1.xpm"
# define MLX_TEX2	"rsrc/textures/wall2.xpm"
# define MLX_TEX3	"rsrc/textures/wall3.xpm"
# define MLX_TEX4	"rsrc/textures/wall4.xpm"
# define MLX_TEX5	"rsrc/textures/open.xpm"
# define MLX_TEX6	"rsrc/textures/open30.xpm"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		xpm_to_img(t_vars *vars, t_list **textures, char *filename);
int		new_screen(t_vars *vars, t_img *img, int width, int height);
int		load_textures(t_vars *vars);
void	destroy_textures(void *textures);

# endif

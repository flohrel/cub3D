/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:08:58 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/15 19:39:55 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_UTILS_H
# define IMG_UTILS_H

# include <time.h>
# include "mlx.h"
# include "data_type.h"
# include "color.h"
# include "libft.h"

# define TEX_WIDTH	64
# define TEX_HEIGHT	64

# define MLX_TEX0	"mlx_Linux/test/open.xpm"
# define MLX_TEX1	"mlx_Linux/test/open30.xpm"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		xpm_to_img(t_vars *vars, t_list **textures, char *filename);
void	get_fps(t_vars *vars, t_time *time);
int		new_screen(t_vars *vars, t_img *img, int width, int height);
void	destroy_textures(void *textures);

# endif

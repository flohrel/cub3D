/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:07:14 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/11 19:05:49 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_2D_H
# define DRAW_2D_H

# include <mlx.h>
# include <math.h>
# include "structs.h"
# include "stdio.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_rainbow(t_img *img, int x, int y, int mod);
void	draw_circle(t_img *img, int xpos, int ypos, int radius);
void	draw_semicircle(t_img *img, int xpos, int ypos, int radius, int color);
void	draw_square(t_img *img, int xpos, int ypos, int size);

#endif

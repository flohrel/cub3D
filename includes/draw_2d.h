/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:07:14 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/04 20:51:43 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_2D_H
# define DRAW_2D_H

# include <mlx.h>
# include <math.h>
# include "color.h"
# include "structs.h"
# include "stdio.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_rainbow(t_data *img, int x, int y, int mod);
void	draw_circle(t_data *data, int xpos, int ypos, int radius);
void	draw_semicircle(t_data *data, int xpos, int ypos, int radius, int color);
void	draw_square(t_data *data, int xpos, int ypos, int size);

#endif

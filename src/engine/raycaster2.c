/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:30:55 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/14 03:05:45 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	vertical_line(t_img *img, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

void	get_stripe(t_data *data)
{
	int stripelen;
	
	stripelen = (int)(WIN_HEIGHT / data->perpwalldist);
	data->pixeltop = -stripelen / 2 + WIN_HEIGHT / 2;
	if (data->pixeltop < 0)
		data->pixeltop = 0;
	data->pixelbot = stripelen / 2 + WIN_HEIGHT / 2;
	if (data->pixelbot >= WIN_HEIGHT)
		data->pixelbot = WIN_HEIGHT - 1;
}

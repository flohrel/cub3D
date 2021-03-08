/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 19:35:12 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 19:35:52 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_rgb(uint32_t *color, char *rgb_str)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	*color = 0xFF000000;
	rgb = ft_split(rgb_str, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (-1);
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	if ((red < 0 || red > 255) ||
		(green < 0 || green > 255) ||
		(blue < 0 || blue > 255))
		return (-1);
	*color |= red << 16;
	*color |= green << 8;
	*color |= blue;
	free_sstr(rgb);
	return (0);
}

int		get_resolution(t_param *param, char **sstr)
{
	if (!sstr[1] || !sstr[2])
		return (-1);
	param->win_width = ft_atoi(sstr[1]);
	param->win_height = ft_atoi(sstr[2]);
	if (param->win_width <= 0 || param->win_height <= 0)
		return (-1);
	clear_flag((int *)&param->flags, R);
	return (0);
}
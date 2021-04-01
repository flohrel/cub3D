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

int		is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (0);
	}
	return (1);
}

int		parse_rgb(uint32_t *color, char *rgb_str)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;

	*color = 0xFF000000;
	rgb = ft_split(rgb_str, ',');
	if ((!rgb[0] || !rgb[1] || !rgb[2] || rgb[3]) ||
		(!is_number(rgb[0]) || !is_number(rgb[1]) || !is_number(rgb[2])))
	{
		free_sstr(rgb);
		return (-1);
	}
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

int		get_resolution(t_vars *vars, t_param *param, char **sstr)
{
	if (!sstr[0] || !sstr[1] || sstr[2])
		return (-1);
	if (!is_number(sstr[0]) || !is_number(sstr[1]))
		return (-1);
	param->win_width = ft_atoi(sstr[0]);
	param->win_height = ft_atoi(sstr[1]);
	if (param->win_width <= 0 || param->win_height <= 0)
		return (-1);
	get_screen_size(vars, vars->param);
	return (0);
}

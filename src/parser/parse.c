/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:02:30 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/08 16:53:48 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		flag_handle(int *field, int flag)
{
	if (!check_flag(*field, flag))
		return (-1);
	else
	{
		clear_flag(field, flag);
		return (0);
	}
}

int		set_parameter(t_param *param, char **sstr)
{
	int *field;

	field = (int *)&param->flags;
	if (!ft_strcmp(sstr[0], "R") && !flag_handle(field, R))
		return (get_resolution(param, &sstr[1]));
	else if (!ft_strcmp(sstr[0], "NO") && !flag_handle(field, NO))
		param->texture_path[0] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "SO") && !flag_handle(field, SO))
		param->texture_path[1] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "EA") && !flag_handle(field, EA))
		param->texture_path[2] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "WE") && !flag_handle(field, WE))
		param->texture_path[3] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "S") && !flag_handle(field, S))
		param->texture_path[4] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "F") && !flag_handle(field, F))
		return (parse_rgb(&param->floor_color, sstr[1]));
	else if (!ft_strcmp(sstr[0], "C") && !flag_handle(field, C))
		return (parse_rgb(&param->ceil_color, sstr[1]));
	else
		return (-1);
	return (0);
}

int		parse_param(int fd, t_param *param)
{
	int		ret;
	char	*line;
	char	**sstr;

	ret = 1;
	param->flags = 0xFF;
	while (param->flags && ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		sstr = ft_split(line, ' ');
		if (*sstr && set_parameter(param, sstr) == -1)
			ret = error_handler("Bad .cub file - bad parameter");
		free(line);
		free_sstr(sstr);
	}
	return (ret);
}

int		parser(t_vars *vars, int ac, char **av)
{
	int		fd;
	t_param	*param;

	param = vars->param;
	if (ac < 2 || ac > 3)
		return (error_handler("Wrong number of argument"));
	else if (ac == 3)
	{
		if (!ft_strcmp(av[2], "--save"))
			vars->save = true;
		else
			return (error_handler("Bad argument"));
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error_handler(av[1]));
	if (parse_param(fd, param) == -1)
		return (ERROR);
	if (param->flags)
		return (error_handler("Bad .cub file - parameter missing"));
	if (parse_map(fd, vars, param) == -1)
		return (error_handler("Bad map"));
	if (close(fd) == -1)
		return (error_handler(NULL));
	return (0);
}

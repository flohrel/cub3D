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

int		set_parameter(t_param *param, char **sstr)
{
	if (!ft_strcmp(sstr[0], "R"))
		return (get_resolution(param, sstr));
	else if (!ft_strcmp(sstr[0], "NO") && clear_flag((int *)&param->flags, NO))
		param->texture_path[0] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "SO") && clear_flag((int *)&param->flags, SO))
		param->texture_path[1] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "EA") && clear_flag((int *)&param->flags, EA))
		param->texture_path[2] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "WE") && clear_flag((int *)&param->flags, WE))
		param->texture_path[3] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "S") && clear_flag((int *)&param->flags, S))
		param->texture_path[4] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "F") && clear_flag((int *)&param->flags, F))
		return (parse_rgb(&param->floor_color, sstr[1]));
	else if (!ft_strcmp(sstr[0], "C") && clear_flag((int *)&param->flags, C))
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

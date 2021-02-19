/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:02:30 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/19 15:25:47 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		error_handler(char *error_msg)
{
	printf("Error\n");
	if (error_msg)
		printf("%s", error_msg);
	if (errno)
		printf(": %s", strerror(errno));
	return (ERROR);
}

void	free_sstr(char **sstr)
{
	char	**s;

	s = sstr;
	while (*sstr)
		free(*sstr++);
	free(s);
}

int		parse_rgb(uint32_t *color, char *rgb_str)
{
	char **rgb;

	*color = 0xFF000000;
	rgb = ft_split(rgb_str, ',');
	if (!rgb[0] || !rgb[1] || !rgb[2])
		return (-1);
	*color |= ft_atoi(rgb[0]) << 16;
	*color |= ft_atoi(rgb[1]) << 8;
	*color |= ft_atoi(rgb[2]);
	free_sstr(rgb);
	return (0);
}

int		set_parameter(t_param *param, char **sstr)
{
	if (!ft_strcmp(sstr[0], "R"))
	{
		if (!sstr[1] || !sstr[2])
			return (-1);
		param->win_width = ft_atoi(sstr[1]);
		param->win_height = ft_atoi(sstr[2]);
		if (param->win_width <= 0 || param->win_height <= 0)
			return (-1);
		clear_flag((int *)&param->flags, R);
	}
	else if (!ft_strcmp(sstr[0], "NO") && clear_flag((int *)&param->flags, NO))
		param->texture_path[0] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "SO") && clear_flag((int *)&param->flags, SO))
		param->texture_path[1] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "WE") && clear_flag((int *)&param->flags, WE))
		param->texture_path[2] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "EA") && clear_flag((int *)&param->flags, EA))
		param->texture_path[3] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "S") && clear_flag((int *)&param->flags, S))
		param->texture_path[4] = ft_strdup(sstr[1]);
	else if (!ft_strcmp(sstr[0], "F") && clear_flag((int *)&param->flags, F))
		return (parse_rgb(&param->floor_color, sstr[1]));
	else if (!ft_strcmp(sstr[0], "C") && clear_flag((int *)&param->flags, C))
		return (parse_rgb(&param->ceil_color, sstr[1]));
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

int		parse_map(int fd, int **map, t_param *param)
{
	int		ret;
	char	*line;
	t_list	*

	ret = 1;
	param->map_height = 0;
	while (ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		ft_lstadd_back();
		free(line);
	}
	if (ret == -1)
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
		if (!ft_strncmp(av[2], "--save", 6))
			param->save = true;
		else
			return (error_handler("Bad argument"));
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error_handler(NULL));
	if (parse_param(fd, param) == -1)
		return (ERROR);
	if (param->flags)
		return (error_handler("Bad .cub file - parameter missing"));
	if (parse_map(fd, vars->map, param) == -1)
		return (error_handler("Bad .cub file - map error"));
	return (0);
}

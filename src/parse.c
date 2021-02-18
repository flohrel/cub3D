/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:02:30 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 14:53:35 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		error_handler(char *error_msg)
{
	printf("Error\n");
	if (errno == 0)
		perror(error_msg);
	else
		printf("%s", strerror(errno));
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

int		set_parameter(t_param *param, char **sstr)
{
	if (ft_strcmp(sstr[0], "R"))
	{
		if (!sstr[1] || !sstr[2])
			return (-1);
		param->win_width = ft_atoi(sstr[1]);
		param->win_height = ft_atoi(sstr[2]);
		if (param->win_width <= 0 || param->win_height <= 0)
			return (-1);
		clear_flag(&param->flags, R);
	}
	else if (ft_strcmp(sstr[0], "NO"))
		ft_strcpy(param->texture_path)[0]
}

int		parse_param(int fd, t_param *param)
{
	int		ret;
	char	*line;
	char	**sstr;

	ret = 1;
	param->flags = 0xFFFFFF;
	while (param->flags || ret > 0)
	{
		line = NULL;
		ret = get_next_line(fd, &line);
		sstr = ft_split(line, ' ');
		if (*sstr && set_parameter(param, sstr) == -1)
			ret = error_handler("Bad .cub file - bad parameter");
		free(line);
		free(sstr);
	}
	return (ret);
}

int		parser(t_vars *vars, int ac, char **av)
{
	int		fd;

	errno = 0;
	if (ac < 2 || ac > 3)
		return (error_handler("Wrong number of argument"));
	else if (ac == 3 &&
			(ft_strlen(av[2]) != 6 || ft_strncmp(av[2], "--save", 6)))
		return (error_handler("Bad argument"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error_handler(NULL));
	if (parse_param(fd, vars->param) == -1)
		return (ERROR);
	if (param->flags)
		return (error_handler("Bad .cub file - parameter missing"));
	if (load_texture(vars, vars->param) == -1)
		return (error_handler("Bad .cub file - texture not found"));
	if (parse_map(fd, vars->map) == -1)
		return (error_handler("Bad .cub file - map error"));
	return (0);
}

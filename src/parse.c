/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:02:30 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/17 17:05:18 by flohrel          ###   ########.fr       */
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

void	free_strstr(char ***strstr)
{
	while (**strstr)
		free(**strstr);
	free(*strstr);
}

int		parse_file(int fd, t_param *param)
{
	char	**args;
	char	*line;
	int		ret;

	line = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret > 0)
		{
			args = ft_split(line, ' ');
			if ((args / sizeof(char *)) == 2)
				parse_param(args);
			else
			{
				if (param->flags)
					return (error_handler("Bad map file - parameter missing"));
				parse_map(param);
			}
		}
		free_strstr(&args);
	}
	free(line);
}

int		parser(t_param *param, int ac, char **av)
{
	int	fd;

	errno = 0;
	if (ac < 2 || ac > 3)
		return (error_handler("Wrong number of argument"));
	else if (ac == 3 &&
			(ft_strlen(av[2]) != 6 || ft_strncmp(av[2], "--save", 6)))
		return (error_handler("Bad argument"));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (error_handler(NULL));
	if (parse_file(fd, param) == -1)
		return (ERROR);
	return (0);
}

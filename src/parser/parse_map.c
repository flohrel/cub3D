/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:10:19 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/22 16:51:52 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**map_alloc(char *line, t_param *param, int index)
{
	char	**map;

	param->map_height = index;
	map = ft_calloc(index + 1, sizeof(char *));
	if (!map)
		return (map);
	map[index] = NULL;
	if (*line)
		map[index - 1] = line;
	else
		free(line);
	return (map);
}

char	**get_map(int fd, t_param *param, int index)
{
	int		ret;
	char	*line;
	char	**map;

	line = NULL;
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (NULL);
	if (ret == 0)
	{
		if (*line)
			map = map_alloc(line, param, index + 1);
		else
			map = map_alloc(line, param, index);
		return (map);
	}
	if (!(*line))
	{
		free(line);
		return (get_map(fd, param, index));
	}
	map = get_map(fd, param, index + 1);
	map[index] = line;
	return (map);
}

int		seek_walls(char **map, int y, int x)
{
	if ()
	if (map[y][x])
}

int		get_borders(t_param *param, char **map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < param->map_height)
	{
		x = -1;
		while (++x < param->map_width)
		{
			if (!map[y][x] && (seek_walls(map, y, x) == -1))
				return (ERROR);
		}
	}
}

int		parse_map(int fd, char **map, t_param *param)
{
	int	len;
	int	i;

	map = get_map(fd, param, 0);
	if (!map)
		return (error_handler(NULL));
	else
	{
		i = -1;
		while (map[++i])
		{
			len = ft_strlen(map[i]);
			if (len > param->map_width)
				param->map_width = len;
		}
		if (get_borders(map) == -1)
			return (ERROR);
	}
	return (0);
}

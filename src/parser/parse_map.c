/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:10:19 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/23 03:12:11 by flohrel          ###   ########.fr       */
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

int		get_direction(char cardinal, t_vect *dir)
{
	if (cardinal == 'N')
	{
		dir->x = -1;
		dir->y = 0;
	}
	else if (cardinal == 'S')
	{
		dir->x = 1;
		dir->y = 0;
	}
	else if (cardinal == 'W')
	{
		dir->x = 0;
		dir->y = 1;
	}
	else
	{
		dir->x = 0;
		dir->y = -1;
	}
}

int		get_position(t_param *param, char **map)
{
	int		x;
	int		y;
	bool	found;

	y = -1;
	found = false;
	while (++y < param->map_height)
	{
		x = -1;
		while (++x < param->map_width)
		{
			if (ft_isalpha(map[y][x]))
			{
				printf("pos:y=%dx=%d dir:%c\n", y, x, map[y][x]);
				found = true;
				param->pos.x = x;
				param->pos.y = y;
				get_direction(map[y][x], &param->dir);
			}
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
		if (get_position(map) == -1)
			return (ERROR);
	}
	return (0);
}

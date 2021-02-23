/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:10:19 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/23 04:25:24 by flohrel          ###   ########.fr       */
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
	else if (cardinal == 'E')
	{
		dir->x = 0;
		dir->y = -1;
	}
	else
		return (-1);
	return (0);
}

/* this function also checks bad chars
*/
int		get_position(t_param *param, char **map)
{
	t_ivect	pos;
	bool	found;

	pos.y = -1;
	found = false;
	while (++pos.y < param->map_height)
	{
		pos.x = -1;
		while (++(pos.x) < param->map_width)
		{
			if (!ft_strchr("012NSEW ", map[pos.y][pos.x]))
				return (ERROR);
			if (ft_isupper(map[pos.y][pos.x]))
			{
				if (found == true)
					return (ERROR);
				found = true;
				param->pos.x = pos.x;
				param->pos.y = pos.y;
				if (get_direction(map[pos.y][pos.x], &param->dir) == -1)
					return (ERROR);
			}
		}
	}
	return (SUCCESS);
}

int		parse_map(int fd, char **map, t_data *data, t_param *param)
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
		if (get_position(param, map) == -1)
			return (ERROR);
		if (check_borders(param, map));
			return (ERROR);
		char_to_int(data, map);
	}
	return (0);
}

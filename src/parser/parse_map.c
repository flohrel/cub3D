/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 13:10:19 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 19:45:32 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**char_map_alloc(char *line, t_param *param, int index)
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
			map = char_map_alloc(line, param, index + 1);
		else
			map = char_map_alloc(line, param, index);
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

void	get_direction(char cardinal, t_data *data)
{
	data->dir.x = 0;
	data->dir.y = 0;
	data->plane.x = 0;
	data->plane.y = 0;
	if (cardinal == 'N')
	{
		data->dir.y = -1;
		data->plane.x = -0.66;
	}
	else if (cardinal == 'S')
	{
		data->dir.y = 1;
		data->plane.x = 0.66;
	}
	else if (cardinal == 'W')
	{
		data->dir.x = 1;
		data->plane.y = -0.66;
	}
	else if (cardinal == 'E')
	{
		data->dir.x = -1;
		data->plane.y = 0.66;
	}
}

int		get_position(t_param *param, t_data *data, char **map)
{
	t_ivect	pos;
	bool	found;

	pos.y = -1;
	found = false;
	while (++pos.y < param->map_height)
	{
		pos.x = -1;
		while (map[pos.y][++(pos.x)])
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
				get_direction(map[pos.y][pos.x], data);
			}
		}
	}
	return (SUCCESS);
}

int		parse_map(int fd, t_vars *vars, t_param *param)
{
	int		ret;
	int		len;
	int		i;

	ret = SUCCESS;
	vars->map = get_map(fd, param, 0);
	if (!vars->map)
		return (error_handler(NULL));
	else
	{
		i = -1;
		while (vars->map[++i])
		{
			len = ft_strlen(vars->map[i]);
			if (len > param->map_width)
				param->map_width = len;
		}
		if (get_position(param, vars->data, vars->map) == -1 ||
			check_borders(vars, param) == -1)
			ret = ERROR;
		free_sstr(vars->map);
	}
	return (ret);
}

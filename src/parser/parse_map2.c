/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:28:48 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 19:45:22 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	is_outside(int y, int x, t_vars *vars)
{
	t_param *param;

	param = vars->param;
	if (y < 0 || y == param->map_height || x < 0 || !vars->map[y][x])
		return (1);
	if (vars->map[y][x] == ' ')
		return (1);
	return (0);
}

int	check_borders2(int y, int x, char **check_grid, t_vars *vars)
{
	if (is_outside(y - 1, x - 1, vars))
		return (-1);
	check_grid[y][x] = 1;
	if (vars->map[y - 1][x - 1] == '1')
		return (0);
	if ((!check_grid[y + 1][x - 1] &&
			check_borders2(y + 1, x - 1, check_grid, vars) == -1) ||
		(!check_grid[y + 1][x] &&
			check_borders2(y + 1, x, check_grid, vars) == -1) ||
		(!check_grid[y + 1][x + 1] &&
			check_borders2(y + 1, x + 1, check_grid, vars) == -1) ||
		(!check_grid[y][x - 1] &&
			check_borders2(y, x - 1, check_grid, vars) == -1) ||
		(!check_grid[y][x + 1] &&
			check_borders2(y, x + 1, check_grid, vars) == -1) ||
		(!check_grid[y - 1][x - 1] &&
			check_borders2(y - 1, x - 1, check_grid, vars) == -1) ||
		(!check_grid[y - 1][x] &&
			check_borders2(y - 1, x, check_grid, vars) == -1) ||
		(!check_grid[y - 1][x + 1] &&
			check_borders2(y - 1, x + 1, check_grid, vars) == -1))
		return (-1);
	return (0);
}

int	int_map_alloc(t_param *param)
{
	int	i;

	param->map = ft_calloc(param->map_width, sizeof(int *));
	if (!param->map)
		return (ERROR);
	i = -1;
	while (++i < param->map_width)
	{
		param->map[i] = ft_calloc(param->map_height, sizeof(int));
		if (!param->map[i])
			return (ERROR);
	}
	return (SUCCESS);
}

int	char_to_int(t_vars *vars, t_param *param, char **check_grid)
{
	int	i;
	int	j;

	if (int_map_alloc(param) == -1)
		return (ERROR);
	i = -1;
	while (++i < param->map_width)
	{
		j = -1;
		while (++j < param->map_height)
		{
			if (!check_grid[j + 1][i + 1])
				param->map[param->map_width - i - 1][j] = 1;
			else if (vars->map[j][i] == '2')
			{
				if (add_sprite(vars, param->map_width - i - 1, j) == -1)
					return (ERROR);
				param->map[param->map_width - i - 1][j] = 0;
			}
			else
				param->map[param->map_width - i - 1][j] = vars->map[j][i] - '0';
		}
	}
	param->map[param->map_width - param->pos.x - 1][param->pos.y] = 0;
	return (SUCCESS);
}

int	check_borders(t_vars *vars, t_param *param)
{
	char	**check_grid;
	int		ret;
	int		i;

	ret = ERROR;
	check_grid = ft_calloc(param->map_height + 2, sizeof(char *));
	if (!check_grid)
		return (ret);
	i = -1;
	while (++i < param->map_height + 2)
	{
		check_grid[i] = ft_calloc(param->map_width + 2, sizeof(char));
		if (!check_grid[i])
			return (ret);
		ft_bzero(check_grid[i], param->map_width + 2);
	}
	if (check_borders2(param->pos.y + 1, param->pos.x + 1,
				check_grid, vars) == 0)
		ret = SUCCESS;
	if (ret == SUCCESS)
		char_to_int(vars, param, check_grid);
	while (--i >= 0)
		free(check_grid[i]);
	free(check_grid);
	return (ret);
}

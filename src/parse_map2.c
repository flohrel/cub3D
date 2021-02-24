/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:28:48 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/24 16:42:07 by flohrel          ###   ########.fr       */
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
	if (is_outside(y, x, vars))
		return (-1);
	check_grid[y][x] = 1;
	if (vars->map[y][x] == '1')
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


int	check_borders(t_vars *vars, t_param *param)
{
	char	**check_grid;
	int		ret;
	int		i;

	ret = ERROR;
	check_grid = ft_calloc(param->map_height, sizeof(char *));
	if (!check_grid)
		return (ret);
	i = -1;
	while (++i < param->map_height)
	{
		check_grid[i] = ft_calloc(param->map_width, sizeof(char));
		if (!check_grid[i])
			return (ret);
		ft_bzero(check_grid[i], param->map_width);
	}
	if (check_borders2(param->pos.y, param->pos.x, check_grid, vars) == 0)
		ret = SUCCESS;
	i = -1;
	while (++i < param->map_height)
		free(check_grid[i]);
	free(check_grid);
	return (ret);
}

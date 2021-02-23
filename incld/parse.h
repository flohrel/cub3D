/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:03:20 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/23 04:25:09 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

int		parser(t_vars *vars, int ac, char **av);
int		parse_map(int fd, char **map, t_data *data, t_param *param);
int		error_handler(char *error_msg);

#endif

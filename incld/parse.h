/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:03:20 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 19:36:56 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "cub3d.h"

int		parser(t_vars *vars, int ac, char **av);
int		parse_map(int fd, t_vars *vars, t_param *param);
int		check_borders(t_vars *vars, t_param *param);
void	free_sstr(char **sstr);
int		error_handler(char *error_msg);
int		get_resolution(t_param *param, char **sstr);
int		parse_rgb(uint32_t *color, char *rgb_str);

#endif

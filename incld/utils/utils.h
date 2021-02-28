/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:55:35 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/28 20:16:30 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

int		error_handler(char *error_msg);
void	free_sstr(char **sstr);
int		add_sprite(t_vars *vars, int x, int y);
void	del_sprite(void *to_del);

#endif

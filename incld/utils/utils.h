/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:55:35 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/08 17:00:15 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

/*
**		utils.c
*/
int				error_handler(char *error_msg);
void			free_sstr(char **sstr);
int				add_sprite(t_vars *vars, int x, int y);
void			del_sprite(void *to_del);
void			sort_sprites(t_list **sprite_lst);

/*
**		init.c
*/
int				init_data(t_vars *vars, t_param *param,
					t_data *data, t_time *time);
void			init_vars(t_vars *vars, t_param *param,
					t_data *data, t_img *screen);

/*
**		bitmap.c
*/
int				data_to_bmp(t_param *param, t_img *screen);

#endif

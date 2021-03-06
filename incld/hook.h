/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 06:12:39 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/16 13:09:13 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "data.h"
# include "utils/keycode.h"
# include "utils/flag.h"
# include "cub3d.h"

/*
**		keyboard.c
*/
int		key_release(int keycode, int *bitfield);
int		key_press(int keycode, int *bitfield);

#endif

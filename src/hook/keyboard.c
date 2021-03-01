/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 06:09:49 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 19:44:45 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

int		key_press(int keycode, int *bitfield)
{
	if (keycode == ESCAPE)
		set_flag(bitfield, ESC);
	if (keycode == TURN_LEFT)
		set_flag(bitfield, TL);
	if (keycode == TURN_RIGHT)
		set_flag(bitfield, TR);
	if (keycode == FORWARD)
		set_flag(bitfield, FW);
	if (keycode == BACKWARD)
		set_flag(bitfield, BW);
	if (keycode == LEFT)
		set_flag(bitfield, LT);
	if (keycode == RIGHT)
		set_flag(bitfield, RT);
	return (0);
}

int		key_release(int keycode, int *bitfield)
{
	if (keycode == TURN_LEFT)
		clear_flag(bitfield, TL);
	if (keycode == TURN_RIGHT)
		clear_flag(bitfield, TR);
	if (keycode == FORWARD)
		clear_flag(bitfield, FW);
	if (keycode == BACKWARD)
		clear_flag(bitfield, BW);
	if (keycode == LEFT)
		clear_flag(bitfield, LT);
	if (keycode == RIGHT)
		clear_flag(bitfield, RT);
	return (0);
}

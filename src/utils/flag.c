/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:27:25 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 16:37:49 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_flag(int *field, int flag)
{
	return ((*field) |= flag);
}

int		check_flag(int field, int flag)
{
	return (field & flag);
}

int		clear_flag(int *field, int flag)
{
	(*field) &= ~(flag);
	return (1);
}

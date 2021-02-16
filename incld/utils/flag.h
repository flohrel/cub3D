/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:29:06 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/12 06:42:23 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define ESC		1
# define SP			2
# define FW			4
# define BW			8
# define L			16
# define R			32
# define TL			64
# define TR			128

int		set_flag(int *field, int flag);
int		check_flag(int field, int flag);
void	clear_flag(int *field, int flag);

#endif

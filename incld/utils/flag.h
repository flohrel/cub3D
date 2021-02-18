/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 20:29:06 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/18 16:35:05 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

/*
**		parameters
*/
# define R			1
# define NO			2
# define SO			4
# define WE			8
# define EA			16
# define S			32
# define F			64
# define C			128

/*
**		keyboard
*/
# define ESC		1
# define SP			2
# define FW			4
# define BW			8
# define LT			16
# define RT			32
# define TL			64
# define TR			128

int		set_flag(int *field, int flag);
int		check_flag(int field, int flag);
int		clear_flag(int *field, int flag);

#endif

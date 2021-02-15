/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:43:43 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/15 14:28:17 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef __linux__
#  define ESCAPE		65307
#  define SPACE			' '
#  define FORWARD		'w'
#  define BACKWARD		's'
#  define LEFT			'a'
#  define RIGHT			'd'
#  define TURN_LEFT		65361
#  define TURN_RIGHT	65363
# elif __APPLE__
#  define ESCAPE		53
#  define SPACE			49
#  define FORWARD		13
#  define BACKWARD		1
#  define LEFT			0
#  define RIGHT			2
#  define TURN_LEFT		123
#  define TURN_RIGHT	124
# endif

#endif


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:24:13 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/07 17:28:29 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

# define FORWARD		0x01
# define LEFT			0x02
# define RIGHT			0x04
# define BACKWARD		0x08
# define TURN_LEFT		0x10
# define TURN_RIGHT		0x20
# define ACTION			0x40
# define EXIT			0x80

int		set_flag(char *field, char flag);
int		check_flag(char field, char flag);
void	clear_flag(char *field, char flag);

#endif

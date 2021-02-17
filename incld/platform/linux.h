/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:39:49 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/17 15:08:42 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_H
# define LINUX_H

# include "cub3d.h"

# define EXIT_EVENT		33
# define EXIT_WIN_MASK	(1L << 5)

int		exit_program(t_vars *vars);

#endif

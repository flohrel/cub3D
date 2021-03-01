/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:39:49 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 20:01:22 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_H
# define LINUX_H

# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "data.h"
# include "utils/image.h"

# define LINUX			1
# define MAC			0
# define EXIT_EVENT		33
# define EXIT_WIN_MASK	32

int		exit_program(t_vars *vars);
void	get_screen_size(t_vars *vars, t_param *param);

#endif

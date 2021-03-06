/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:39:47 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/01 20:02:13 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAC_H
# define MAC_H

# include <sys/uio.h>
# include <unistd.h>
# include "mlx.h"
# include "data.h"
# include "utils/image.h"

# define LINUX			1
# define MAC			0
# define EXIT_EVENT		17
# define EXIT_WIN_MASK	131072

int		exit_program(t_vars *vars);
void	get_screen_size(t_vars *vars, t_param *param);

#endif

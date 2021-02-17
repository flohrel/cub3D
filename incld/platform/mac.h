/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:39:47 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/17 16:04:40 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAC_H
# define MAC_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "mlx.h"
# include "data.h"
# include "utils/image.h"

# define EXIT_EVENT		17
# define EXIT_WIN_MASK	(1L << 17)

int		exit_program(t_vars *vars);

#endif

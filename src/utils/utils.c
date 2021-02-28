/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:54:10 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/28 05:42:19 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"

int		error_handler(char *error_msg)
{
	printf("Error\n");
	if (error_msg)
		printf("%s", error_msg);
	if (errno)
		printf(": %s", strerror(errno));
	return (ERROR);
}

void	free_sstr(char **sstr)
{
	char	**s;

	s = sstr;
	while (*sstr)
		free(*sstr++);
	free(s);
}

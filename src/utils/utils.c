/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 04:54:10 by flohrel           #+#    #+#             */
/*   Updated: 2021/03/05 15:20:13 by flohrel          ###   ########.fr       */
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

void	del_sprite(void *to_del)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)to_del;
	free(sprite);
}

int		add_sprite(t_vars *vars, int x, int y)
{
	t_list		*new_lst;
	t_sprite	*new_sprite;

	new_sprite = ft_calloc(1, sizeof(t_sprite));
	if (!new_sprite)
		return (ERROR);
	new_sprite->pos.x = (float)x + 0.5;
	new_sprite->pos.y = (float)y + 0.5;
	new_sprite->distance = 0;
	new_lst = ft_lstnew(new_sprite);
	if (!new_lst)
		return (ERROR);
	ft_lstadd_back(&vars->sprites, new_lst);
	return (SUCCESS);
}

void	sort_sprites(t_list **sprite_lst)
{
	t_sprite	*sprite;
	t_list		*lptr;
	t_list		*next;
	bool		is_sort;

	is_sort = false;
	while (is_sort == false)
	{
		is_sort = true;
		lptr = *sprite_lst;
		while (lptr && (next = lptr->next) != NULL)
		{
			if (((t_sprite *)lptr->content)->distance <
				((t_sprite *)next->content)->distance)
			{
				is_sort = false;
				sprite = next->content;
				next->content = lptr->content;
				lptr->content = sprite;
			}
			else
				lptr = next;
		}
	}
}

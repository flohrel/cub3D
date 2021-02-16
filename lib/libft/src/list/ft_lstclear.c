/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flohrel <flohrel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:51:19 by flohrel           #+#    #+#             */
/*   Updated: 2021/02/15 19:55:18 by flohrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lptr;
	t_list	*next;

	if (lst && *lst && del)
	{
		lptr = *lst;
		while (lptr)
		{
			next = lptr->next;
			ft_lstdelone(lptr, del);
			lptr = next;
		}
		*lst = NULL;
	}
}

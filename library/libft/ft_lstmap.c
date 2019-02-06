/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:19:59 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/28 14:20:30 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*nelem;
	t_list	*pred;

	new = NULL;
	if (lst && (*f))
	{
		new = (*f)(lst);
		pred = new;
		lst = lst->next;
		while (lst)
		{
			nelem = (*f)(lst);
			pred->next = nelem;
			pred = nelem;
			lst = lst->next;
		}
		pred->next = NULL;
	}
	return (new);
}

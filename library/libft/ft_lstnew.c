/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:15:45 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/28 14:16:14 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *s;

	s = (t_list*)malloc(sizeof(t_list));
	if (s == NULL)
		return (NULL);
	if (content == NULL)
	{
		s->content = NULL;
		s->content_size = 0;
	}
	else
	{
		s->content = malloc(content_size);
		if (s->content == NULL)
			return (NULL);
		ft_memcpy(s->content, content, content_size);
		s->content_size = content_size;
	}
	s->next = NULL;
	return (s);
}

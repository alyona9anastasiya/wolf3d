/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:51:20 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/08 20:21:28 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	const char	*s;
	size_t		j;
	size_t		i;
	size_t		z;

	i = 0;
	if (*n == '\0')
		return (char*)h;
	while (i != len && h[i] != '\0')
	{
		s = 0;
		if (h[i] == n[0])
		{
			z = i;
			j = 0;
			s = &h[i];
			while (n[j] != '\0' && n[j++] == h[z++])
				if (n[j] == '\0' && z <= len)
					return (char*)s;
		}
		i++;
	}
	return (0);
}

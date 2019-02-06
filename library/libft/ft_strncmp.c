/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:42:37 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/11 15:17:20 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1++ != *s2++)
			return (*(const unsigned char*)(s1 - 1)
					- *(const unsigned char*)(s2 - 1));
		else if (*s1 == '\0' && *s2 == '\0')
			return (0);
	}
	return (0);
}

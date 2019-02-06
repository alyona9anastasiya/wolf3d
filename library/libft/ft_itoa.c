/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:36:09 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/20 14:51:20 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*c;
	int			start;
	int			len;
	long long	res;

	start = 0;
	res = (long long)n;
	len = ft_itoa_aslan(res);
	c = (char*)malloc(sizeof(char) * (len + 1));
	if (c == 0)
		return (0);
	c[len] = '\0';
	if (res < 0)
	{
		c[start++] = '-';
		res = -res;
	}
	while (len > 0 && len > start)
	{
		c[--len] = (res % 10) + '0';
		res = res / 10;
	}
	return (c);
}

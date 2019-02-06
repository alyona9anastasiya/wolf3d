/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slova.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:03:59 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/28 14:04:43 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_slova(char const *str, char k)
{
	int	a;
	int	c;
	int	i;

	c = 0;
	i = 0;
	a = ft_strlen(str);
	while (str[i] == k)
		i++;
	while (str[a] == k)
		a--;
	while (i < a)
	{
		if (str[i] == k && str[i + 1] != k && str[i + 1] != '\0')
			c++;
		i++;
	}
	if (str[0] != '\0')
		c++;
	return (c);
}

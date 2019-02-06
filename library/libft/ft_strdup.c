/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 21:10:06 by avatseba          #+#    #+#             */
/*   Updated: 2018/09/13 15:53:09 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int			i;
	int			counter;
	char		*pntr;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		i++;
		counter++;
	}
	i = 0;
	pntr = (char *)malloc(counter * sizeof(*pntr) + 1);
	if (!pntr)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		pntr[i] = str[i];
		i++;
	}
	pntr[i] = '\0';
	return (pntr);
}

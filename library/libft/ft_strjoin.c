/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:33:44 by avatseba          #+#    #+#             */
/*   Updated: 2018/09/13 15:54:21 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*pntr;

	i = 0;
	if (!s1 || !s2)
	{
		return (NULL);
	}
	pntr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!pntr)
	{
		return (NULL);
	}
	ft_strcpy(pntr, s1);
	ft_strcat(pntr, s2);
	return (pntr);
}

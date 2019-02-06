/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:33:08 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/21 17:42:52 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		l;
	int		y;
	int		z;
	char	**tab;

	y = 0;
	l = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_slova(s, c) + 1))))
		return (NULL);
	while (s[l])
	{
		while ((s[l] == c) && s[l])
			l++;
		if (s[l])
		{
			z = 0;
			if (!(tab[y] = (char*)malloc(ft_dovz(s, l, c) + 1)))
				return (NULL);
			while (s[l] != c && s[l])
				tab[y][z++] = s[l++];
			tab[y++][z] = '\0';
		}
	}
	tab[y] = NULL;
	return (tab);
}

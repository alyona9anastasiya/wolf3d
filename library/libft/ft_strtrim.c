/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:16:29 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/17 19:25:45 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*d;
	size_t	i;
	size_t	e;

	if (!s)
		return (NULL);
	i = 0;
	e = ft_strlen(s);
	while (ft_iswhitespaces(s[i]))
		i++;
	while (ft_iswhitespaces(s[e - 1]))
		e--;
	if (e < i)
		e = i;
	d = ft_strnew(e - i);
	if (!d)
		return (NULL);
	return (ft_strncpy(d, s + i, e - i));
}

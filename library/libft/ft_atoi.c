/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:36:30 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/13 18:36:55 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	number;
	char				check;

	number = 0;
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	check = '+';
	if (*str == '-' || *str == '+')
	{
		check = *str;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (number > 9223372036854775807)
		return (check == '-' ? 0 : -1);
	return ((check == '-' ? -number : number));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:12:32 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/17 15:22:06 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	number;

	if (n < 0)
	{
		number = -n;
		ft_putchar('-');
	}
	else
		number = n;
	if (number >= 10)
	{
		ft_putnbr(number / 10);
		ft_putchar((number % 10) + '0');
	}
	else
		ft_putchar(number + '0');
}

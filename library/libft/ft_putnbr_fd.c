/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:42:04 by avatseba          #+#    #+#             */
/*   Updated: 2017/11/17 15:45:29 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		number = -n;
		ft_putchar_fd('-', fd);
	}
	else
		number = n;
	if (number >= 10)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putchar_fd((number % 10) + '0', fd);
	}
	else
		ft_putchar_fd(number + '0', fd);
}

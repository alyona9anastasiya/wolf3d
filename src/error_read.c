/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:02:55 by avatseba          #+#    #+#             */
/*   Updated: 2018/11/24 22:39:31 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			ft_error_long(void)
{
	ft_putstr("Fail size");
	exit(0);
}

void			ft_error_notdigit(void)
{
	ft_putstr("Not digit value");
	exit(0);
}

void			ft_error_hex(void)
{
	ft_putstr("Hex not supported!");
	exit(0);
}

void			ft_error_minus(void)
{
	ft_putstr("There is can't be any negative number");
	exit(0);
}

void			ft_error_image_upload(void)
{
	ft_putstr("Error upload image");
	exit(0);
}

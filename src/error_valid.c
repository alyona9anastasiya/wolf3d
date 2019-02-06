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

void			ft_error_fd(void)
{
	ft_putstr("Cat't open file");
	exit(0);
}

void			ft_error_size(void)
{
	ft_putstr("Your map have different row size");
	exit(0);
}

void			ft_get_out(void)
{
	ft_putstr("There no splace to put you player");
	exit(0);
}

void			ft_error_folder(void)
{
	ft_putstr("Stop that madness put file instead of folder");
	exit(0);
}

void			ft_error_malloc(void)
{
	ft_putstr("There some error while malloc");
	exit(0);
}

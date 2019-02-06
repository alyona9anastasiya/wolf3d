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

void			ft_error_init_ttf(void)
{
	ft_putstr(SDL_GetError());
	exit(0);
}

void			ft_error_init_window(void)
{
	ft_putstr(SDL_GetError());
	exit(0);
}

void			ft_error_in_wall(void)
{
	ft_putstr("You in the wall. What you expect to see?");
	exit(0);
}

void			ft_error_out_from_map(void)
{
	ft_putstr("Now you in the space. You happy ?");
	exit(0);
}

void			ft_error_texture(void)
{
	ft_putstr("Texture doesn't exist");
	exit(0);
}

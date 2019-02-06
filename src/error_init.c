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

void			ft_error_ttf(void)
{
	ft_putstr("Error upload ttf");
	exit(0);
}

void			ft_error_render_quality(void)
{
	ft_putstr("Error init rander");
	exit(0);
}

void			ft_error_init_images(void)
{
	ft_putstr("Error init images");
	exit(0);
}

void			ft_error_audios(void)
{
	ft_putstr("Audio error can't parse");
	exit(0);
}

void			ft_error_images(void)
{
	ft_putstr("Images error can't parse");
	exit(0);
}

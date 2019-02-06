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

void			ft_error_resolution(void)
{
	ft_putstr("Fail size");
	exit(0);
}

void			ft_error_bufferization(void)
{
	ft_putstr("Put buffer size back!");
	exit(0);
}

int				ft_define_correct(void)
{
	if ((WIDTH < 320 && HEIGHT < 280) || (WIDTH > 1980 && HEIGHT > 1240))
	{
		ft_error_resolution();
		return (1);
	}
	if (BUFF_SIZE < 1)
	{
		ft_error_bufferization();
		return (1);
	}
	return (0);
}

int				ft_parsing(char *file, t_data *data)
{
	if (ft_define_correct())
		return (0);
	if (ft_validation(file, data) && ft_create_map(file, data))
		ft_correction(data);
	return (1);
}

int				main(int ac, char **av)
{
	t_data		data;

	if (ac < 2)
		return (0);
	ft_bzero(&data, sizeof(t_data));
	if (ft_parsing(av[1], &data))
	{
		ft_init_data(&data);
		ft_init_player(&data.player);
		ft_place_holder_player_map(&data);
		ft_init_window(&data);
		ft_core(&data);
	}
	return (0);
}

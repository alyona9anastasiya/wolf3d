/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:02:55 by avatseba          #+#    #+#             */
/*   Updated: 2018/11/16 20:02:06 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				ft_

int				ft_correct_size(char *file, t_card *card)
{
	int			i;
	int			rewd;

	while (get_next_line(card->fd, &card->line) > 0)
	{
		(*card.line == '\0' && i == 0) && i++;
		(*card.line == '\0' && i == 1) ? ft_error_long() : 0;
		rewd += ft_validation_len(card);
		++card->cheight;
		free(card->line);
	}
	if (get_next_line(card->fd, &card->line) != 0)
		return (0);
	else
	{
		(close(card->fd) == -1) ? ft_error_fd() : 0;
		return (1);
	}
}

int				ft_validation(char *file, t_data *data)
{
	t_card		card;
	//Review is not a directory
	if ((card.fd = open(file, O_RDONLY)) == -1)
		ft_error_fd();
	if (!(ft_correct_size(file, &card)))
		ft_error_size();
	if (card.cwidth < 3 && card.cheight < 3)
		ft_get_out();
	if (ft_card_malloc(data, card))
		ft_error_malloc();
}

int				ft_define_correct(void)
{

	if ((WIDTH < 320 && HEIGHT < 280) || (WIDTH > 1980 && HEIGHT > 1240))
	{
		ft_error_resolution();
		return (1);
	}
	if (BUFFER < 1)
	{
		ft_error_bufferization();
		return (1);
	}
}

int				ft_parsing(char *file, t_data *data)
{
	if (!(ft_define_correct()))
		return(0);
	if (ft_validation(file, data) && (ft_create_map(data))
			ft_correction(data);
	else 
		return (0);
}

int				main(int ac, char **av)
{
	t_data		data;
	
	if (ac < 2)
		return (0);
	ft_bzero(&data, sizeof(t_data));
	ft_parsing(av[1], &data);
	return (0);
}

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

int				ft_map_size_review(t_card *card)
{
	int			i;
	int			n;
	char		**map;
	static int	etax = 1;

	n = 0;
	i = -1;
	map = ft_strsplit(card->line, ' ');
	(etax == 1) ? ft_count_etax(card, map, &etax) : 0;
	while (map[n] != NULL && map[n][0] != 0 && map[n][1] != 10)
		n++;
	if (ft_check(card, map, n) == 1)
	{
		while (map[++i])
			ft_strdel(&map[i]);
		free(map);
		return (1);
	}
	else
	{
		while (*map == NULL && map[++i])
			ft_strdel(&map[i]);
		free(map);
		return (0);
	}
}

int				ft_correct_size(char *file, t_card *card)
{
	int			mapend;

	(void)file;
	mapend = 0;
	while (get_next_line(card->fd, &card->line) > 0)
	{
		(*card->line == '\0' && mapend == 0) && mapend++;
		(*card->line == '\0' && mapend == 1) ? ft_error_long() : 0;
		if (!ft_map_size_review(card))
			ft_error_long();
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
	char		*buf;

	buf = NULL;
	(void)data;
	if ((card.fd = open(file, O_RDONLY)) == -1)
		ft_error_fd();
	if (read(card.fd, buf, 0) == -1)
		ft_error_folder();
	if (!(ft_correct_size(file, &card)))
		ft_error_size();
	if (card.cwidth < 3 || card.cheight < 3)
		ft_get_out();
	if (!(ft_card_malloc(data, &card)))
		ft_error_malloc();
	return (1);
}

int				ft_create_map(char *file, t_data *data)
{
	int			x;
	int			y;
	int			fd;
	char		*line;

	(void)data;
	y = 0;
	((fd = open(file, O_RDONLY)) == -1) ? ft_error_fd() : 0;
	while (get_next_line(fd, &line))
	{
		x = 0;
		ft_filler(data, line, &x, y);
		free(line);
		y++;
	}
	return (1);
}

void			ft_correction(t_data *data)
{
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (y < data->map.map_height)
		data->map.map[y++][0] = 1;
	while (x < data->map.map_width)
		data->map.map[0][++x] = 1;
	x = 0;
	while (x < data->map.map_width)
		data->map.map[data->map.map_height - 1][++x] = 1;
	y = 0;
	while (y < data->map.map_height - 1)
		data->map.map[++y][data->map.map_width - 1] = 1;
}

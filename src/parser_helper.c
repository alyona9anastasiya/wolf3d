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

void			ft_count_etax(t_card *card, char **map, int *etax)
{
	int		i;

	i = 0;
	*etax = 0;
	while (map[i] != NULL && map[i][0] != 0 && map[i][1] != 10)
		i++;
	card->cwidth = i;
}

int				ft_nbr_len(int nbr)
{
	int			len;
	int			res;

	len = 0;
	res = nbr;
	if (nbr == 0)
		return (1);
	while (res != 0)
	{
		res = res / 10;
		len++;
	}
	if (len == 0)
		len++;
	if (nbr < 0)
		len++;
	return (len);
}

int				ft_card_malloc(t_data *data, t_card *card)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	data->map.map_height = card->cheight;
	data->map.map_width = card->cwidth;
	if (!(data->map.map = (int**)malloc(sizeof(int*) *\
	data->map.map_height)))
		return (0);
	while (i < data->map.map_height)
	{
		if ((data->map.map[i] = (int *)malloc(sizeof(int)\
			* data->map.map_width + 1)))
		{
			j = 0;
			while (j < data->map.map_width)
				data->map.map[i][j++] = 0;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int				ft_validval(char **maps)
{
	int			i;
	size_t		tmpd;

	i = 0;
	while (maps[i] != NULL)
	{
		if (ft_isdigit(maps[i][0]) != 1 && maps[i][0] == '-')
			(maps[i][0] == '-' && ft_isdigit(maps[i][1]) != 1) ? \
			ft_error_notdigit() : 0;
		(ft_isalpha(maps[i][0])) ? ft_error_notdigit() : 0;
		tmpd = ft_nbr_len(ft_atoi(maps[i]));
		if (ft_strlen(maps[i]) != tmpd && ft_isascii(maps[i][tmpd]) \
			&& maps[i][tmpd] != ',' && maps[i][0] != '+')
			return (0);
		if (ft_strlen(maps[i]) == tmpd && !(ft_isdigit(maps[i][0])
			|| maps[i][0] == '-'))
		{
			ft_error_notdigit();
			return (0);
		}
		i++;
	}
	return (1);
}

void			ft_filler(t_data *data, char *iter, int *x, int y)
{
	while (*iter != '\0')
	{
		while (*iter == ' ')
			iter++;
		if (*iter == '-' || isdigit(*iter) || *iter == '+')
		{
			if (*iter == '-')
				ft_error_minus();
			if (*iter == '+')
				while (*iter == '+')
					iter++;
			data->map.map[(int)y][(int)*x] = ft_atoi_base(iter, 10);
			(data->map.map[(int)y][(int)*x] > 4 || \
			data->map.map[(int)y][(int)*x] < 0) ? ft_error_image_upload() : 0;
		}
		while (*iter != ' ' && *iter != '\0')
			iter++;
		*x = *x + 1;
	}
}

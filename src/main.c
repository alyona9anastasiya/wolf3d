/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:02:55 by avatseba          #+#    #+#             */
/*   Updated: 2018/11/16 23:51:26 by ylisyak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


//------------------------------------ERROR SECTION---------------------------//
void			ft_error_hex(void)
{
	ft_putstr("Hex not supported!");
	exit(0);
}

void			ft_error_notdigit(void)
{
	ft_putstr("Not digit value");
	exit(0);
}

void			ft_error_folder(void)
{
	ft_putstr("Stop that madness put file instead of folder");
	exit(0);
}

void			ft_error_long(void)
{
	ft_putstr("Fail size");
	exit(0);
}

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

void			ft_error_malloc(void)
{
	ft_putstr("There some error while malloc");
	exit(0);
}

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
//-------------------------- END OF ERROR SECTION ----------------------//
//-------------------------- VALIDATION SECTION ------------------------//
void			ft_count_etax(t_card *card, char **map, int *etax)
{
	int		i;

	i = 0;
	*etax = 0;
	while (map[i] != NULL && map[i][0] != 0 && map[i][1] != 10)
		i++;
	card->cwidth = i;
}

int				ft_border_symbol(char *s, int from)
{
	s += from;
	while (*s)
	{
		if (!((*s >= '0' && *s <= '9') || (*s >= 'A' && *s <= ('A' + 6)) \
		|| (*s >= 'a' && *s <= ('a' + 6))) && *s != '\0')
			ft_error_hex();
		s++;
	}
	return (1);
}

int				ft_validhex(char *map, int tmpd)
{
	int			constnbr;
	char		*cpy;

	constnbr = 6;
	cpy = map;
	if (map[tmpd + 1] == '0' && (map[tmpd + 2] == 'x' ||\
		map[tmpd + 2] == 'X'))
	{
		if (map[tmpd + 3] != '\0')
		{
			if ((constnbr < ft_strlen_from(cpy, (tmpd + 3))))
				return (0);
			if (ft_border_symbol(cpy, (tmpd + 3)) != 1)
				return (0);
		}
		else
			ft_error_hex();
	}
	else
	{
		ft_error_hex();
		return (0);
	}
	return (1);
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

int				ft_validval(char **maps)
{
	int			i;
	size_t		tmpd;

	i = 0;
	while (maps[i] != NULL)
	{
		if (ft_isdigit(maps[i][0]) != 1)
			(maps[i][0] != '-' && !ft_isdigit(maps[i][1])) ? \
			ft_error_notdigit() : 0;
		tmpd = ft_nbr_len(ft_atoi(maps[i]));
		if (ft_strlen(maps[i]) != tmpd && maps[i][tmpd] == ',')
			(ft_validhex(maps[i], tmpd) != 1) ? ft_error_hex() : printf("unsuported!\n");
		if (ft_strlen(maps[i]) != tmpd && ft_isascii(maps[i][tmpd]) \
			&& maps[i][tmpd] != ',')
			return (0);
		i++;
	}
	return (1);
}

int				ft_map_size_review(t_card *card)
{
	int			i;
	int			n;
	char 		**map;
	static int	etax = 1;

	n = 0;
	i = 0;
	map = ft_strsplit(card->line, ' ');
	if (etax == 1)
		ft_count_etax(card, map, &etax);	
	while (map[n] != NULL && map[n][0] != 0 && map[n][1] != 10)
		n++;
	if ((*card->line == '\0' || *card->line == '\n' ||\
	n == card->cwidth) && ft_validval(map))
	{
		while (map[++i])
			ft_strdel(&map[i]);
		free(map);
		return (1);
	}
	else
	{
		while (map[++i])
			ft_strdel(&map[i]);
		free(map);
		return (0);
	}
}

int				ft_correct_size(char *file, t_card *card)
{
	int			mapend;		
		
	mapend = 0;
	(void)file;
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
	char 		*buf = NULL;
	(void)data;
	if ((card.fd = open(file, O_RDONLY)) == -1)
		ft_error_fd();
	if (read(card.fd, buf, 0) == -1)
		ft_error_folder();	
	if (!(ft_correct_size(file, &card)))
		ft_error_size();
	if (card.cwidth < 3 && card.cheight < 3)
		ft_get_out();
	if (!(ft_card_malloc(data, &card)))
		ft_error_malloc();
	return (1);
}
//------------------------- END OF VALIDATION SECTION ------------------//
//-------------------------      MALLOC SECTION       ------------------//
int					ft_card_malloc(t_data *data, t_card *card)
{
	int				i;

	i = 0;
	data->map.map_height = card->cheight;
	data->map.map_width = card->cwidth;
	if (!(data->map.map = (int**)malloc(sizeof(int*) * data->map.map_height)))
		return (0);
	while (i < data->map.map_height)
		if (!(data->map.map[i++] = (int *)malloc(sizeof(int)\
			* data->map.map_width + 1)))
			return (0);
	i = 0;
	while (i < data->map.map_height)
		data->map.map[i++][data->map.map_width] = 0;
	return (1);
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
		return(0);

		ft_validation(file, data);
	   //	&& (ft_create_map(data))
//			ft_correction(data);
//	else
		int		i;
		int 	y;

		i = 0;
		y = 0;

	   while (y < data->map.map_height)
	   {
		   i = 0;
			while (i < data->map.map_width)
			{
				printf("%d ", data->map.map[y][i]);
				i++;
			}
			printf("\n");
			y++;
	   }	   
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

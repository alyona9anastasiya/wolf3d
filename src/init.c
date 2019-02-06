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

void				ft_init_data(t_data *data)
{
	data->status = 2;
	data->process = 1;
	data->walls.quantity = 7;
	data->ceiling.quantity = 1;
	data->floor.quantity = 1;
	data->window = NULL;
	data->screen = NULL;
}

void				ft_init_player(t_player *player)
{
	ft_bzero(player, sizeof(t_player));
	ft_bzero(&player->camera, sizeof(t_camera));
	player->camera.zooming = 1;
	player->pos_x = 1.5;
	player->pos_y = 1.5;
	player->speed = 0.3;
	player->current_speed = 0;
	player->camera.speed = 4 * M_PI / 180;
	player->camera.dir_x = 1;
	player->camera.dir_y = 0;
	player->camera.plane_x = 0.0;
	player->camera.plane_y = 0.66;
}

void				ft_place_holder_player_map(t_data *data)
{
	if ((int)data->player.pos_x > data->map.map_width ||\
			(int)data->player.pos_y > data->map.map_height)
		ft_error_out_from_map();
	else if (data->map.map[(int)data->player.pos_y]\
			[(int)data->player.pos_x] != 0)
		ft_error_in_wall();
}

SDL_Surface			*ft_sdl_scaler(SDL_Surface *main, SDL_Rect *size)
{
	int				h;
	int				w;
	double			cof_x;
	double			cof_y;
	t_uin			uin;

	h = 0;
	ft_checkout(main, &uin);
	(main->w < size->w) ? (cof_x = (double)main->w / (double)size->w) :\
						(cof_x = (double)size->w / (double)main->w);
	(main->h < size->h) ? (cof_y = (double)main->w / (double)size->w) :\
						(cof_y = (double)size->w / (double)main->w);
	while (h < size->h)
	{
		w = 0;
		while (w < size->w)
		{
			uin.tmp_color = uin.tex_col[(int)(cof_x * w) +\
			(int)(cof_y * h) * main->w];
			uin.scr_col[w + h * size->w] = uin.tmp_color;
			w++;
		}
		h++;
	}
	return (uin.scaled);
}

void				ft_main_scaled(t_data *data)
{
	SDL_Rect		space;

	space.x = 0;
	space.y = 0;
	space.w = WIDTH;
	space.h = HEIGHT;
	data->scaled = ft_sdl_scaler(data->walls.texture[0], &space);
}

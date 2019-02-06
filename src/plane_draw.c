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

void			ft_fill_wall(t_data *data, int side)
{
	data->tmp.text_pix = (uint32_t*)data->walls.texture[data->map.map\
	[data->tmp.map_y][data->tmp.map_x] + side]->pixels;
	data->tmp.gx = data->walls.texture[data->map.map[data->tmp.map_y]\
	[data->tmp.map_x] + side]->w;
	data->tmp.gy = data->walls.texture[data->map.map[data->tmp.map_y]\
	[data->tmp.map_x] + side]->h;
	data->tmp.color_pix = data->tmp.text_pix[data->tmp.gy *\
	data->tmp.text_y + data->tmp.text_x];
	if ((data->tmp.y >= 0 && data->tmp.y < HEIGHT))
		data->img[data->tmp.x + data->tmp.y * WIDTH] = data->tmp.color_pix;
}

void			ft_draw_wall(t_data *data)
{
	(data->tmp.start < 0) ? (data->tmp.start = 0) : 0;
	(data->tmp.end >= HEIGHT) ? (data->tmp.end = HEIGHT - 1) : 0;
	data->tmp.y = data->tmp.start;
	while (data->tmp.y < data->tmp.end)
	{
		data->tmp.cof_s = data->tmp.y + data->player.camera.upd -\
		H_H + (data->tmp.l_h >> 1);
		data->tmp.text_y = ((data->tmp.cof_s * data->tmp.gx) / (data->tmp.l_h));
		if (data->tmp.raydir_x > 0 && data->tmp.side == 0)
			ft_fill_wall(data, 0);
		else if (data->tmp.raydir_y > 0 && data->tmp.side == 1)
			ft_fill_wall(data, 1);
		else if (data->tmp.side == 1)
			ft_fill_wall(data, 2);
		else if (data->tmp.side == 0)
			ft_fill_wall(data, 3);
		data->tmp.y++;
	}
}

void			ft_hit_floor(t_data *data)
{
	if (data->tmp.side == 0 && data->tmp.raydir_x > 0)
	{
		data->tmp.floor_x = data->tmp.map_x;
		data->tmp.floor_y = data->tmp.map_y + data->tmp.wall_x;
	}
	else if (data->tmp.side == 0 && data->tmp.raydir_x < 0)
	{
		data->tmp.floor_x = data->tmp.map_x + 1.0;
		data->tmp.floor_y = data->tmp.map_y + data->tmp.wall_x;
	}
	else if (data->tmp.side == 1 && data->tmp.raydir_y > 0)
	{
		data->tmp.floor_x = data->tmp.map_x + data->tmp.wall_x;
		data->tmp.floor_y = data->tmp.map_y;
	}
	else
	{
		data->tmp.floor_x = data->tmp.map_x + data->tmp.wall_x;
		data->tmp.floor_y = data->tmp.map_y + 1.0;
	}
}

void			ft_cf_draw(t_data *data, int y, double dist)
{
	int			temper;
	double		weight;
	double		cfloorx;
	double		cfloory;

	temper = y - data->player.camera.upd;
	weight = (dist - data->tmp.tmpdistplayer) / (data->tmp.tmpdistwall -\
	data->tmp.tmpdistplayer);
	cfloorx = weight * data->tmp.floor_x + (1.0 - weight) *\
	data->player.pos_x;
	cfloory = weight * data->tmp.floor_y + (1.0 - weight) *\
	data->player.pos_y;
	data->tmp.floortex_x = (int)(cfloorx * data->tmp.x0) % data->tmp.x0;
	data->tmp.floortex_y = (int)(cfloory * data->tmp.y0) % data->tmp.y0;
	data->tmp.text_pix = (uint32_t*)data->floor.texture[0]->pixels;
	data->tmp.color_pix = (data->tmp.text_pix[data->tmp.x0 *\
	data->tmp.floortex_y + data->tmp.floortex_x] >> 1) & 8355711;
	if (temper < HEIGHT && temper >= 0)
		data->img[data->tmp.x + (temper) * WIDTH] = data->tmp.color_pix;
	data->tmp.text_pix = (uint32_t*)data->ceiling.texture[0]->pixels;
	data->tmp.color_pix = (data->tmp.text_pix[data->tmp.x1 *\
	data->tmp.floortex_y + data->tmp.floortex_x] >> 1) & 8355711;
	(HEIGHT - data->player.camera.upd - y < HEIGHT && HEIGHT - y -\
	data->player.camera.upd >= 0) ? (data->img[data->tmp.x + (HEIGHT -\
	y - data->player.camera.upd) * WIDTH] = data->tmp.color_pix) : 0;
}

void			ft_cf_viz(t_data *data)
{
	double		dis;
	int			y;

	y = data->tmp.end + 1 + data->player.camera.upd;
	data->tmp.tmpdistwall = data->tmp.walldist;
	data->tmp.tmpdistplayer = 0.0;
	data->tmp.x0 = data->floor.texture[0]->w;
	data->tmp.y0 = data->floor.texture[0]->h;
	data->tmp.x1 = data->ceiling.texture[0]->w;
	data->tmp.y1 = data->ceiling.texture[0]->h;
	while (y < HEIGHT + abs(data->player.camera.upd))
	{
		dis = HEIGHT / (2.0 * y - HEIGHT);
		ft_cf_draw(data, y, dis);
		y++;
	}
}

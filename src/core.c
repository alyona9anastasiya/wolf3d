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

void			ft_calculation_camera(t_data *data)
{
	data->tmp.camera = (data->tmp.x << 1) / (double)WIDTH - 1;
	data->tmp.raydir_x = data->player.camera.dir_x *\
	data->player.camera.zooming + data->player.camera.plane_x *\
	data->tmp.camera;
	data->tmp.raydir_y = data->player.camera.dir_y *\
	data->player.camera.zooming + data->player.camera.plane_y *\
	data->tmp.camera;
	data->tmp.map_x = (int)data->player.pos_x;
	data->tmp.map_y = (int)data->player.pos_y;
	data->tmp.ddist_x = fabs(1.0 / data->tmp.raydir_x);
	data->tmp.ddist_y = fabs(1.0 / data->tmp.raydir_y);
}

void			ft_distance(t_data *data)
{
	ft_calculation_camera(data);
	if (data->tmp.raydir_x < 0)
	{
		data->tmp.step_x = -1;
		data->tmp.sdist_x = \
		(data->player.pos_x - data->tmp.map_x) * data->tmp.ddist_x;
	}
	else
	{
		data->tmp.step_x = 1;
		data->tmp.sdist_x = \
		(data->tmp.map_x + 1.0 - data->player.pos_x) * data->tmp.ddist_x;
	}
	if (data->tmp.raydir_y < 0)
	{
		data->tmp.step_y = -1;
		data->tmp.sdist_y = \
		(data->player.pos_y - data->tmp.map_y) * data->tmp.ddist_y;
	}
	else
	{
		data->tmp.step_y = 1;
		data->tmp.sdist_y = \
		(data->tmp.map_y + 1.0 - data->player.pos_y) * data->tmp.ddist_y;
	}
}

void			ft_hit(t_data *data)
{
	data->tmp.hit = 0;
	while (data->tmp.hit == 0)
	{
		if (data->tmp.sdist_x < data->tmp.sdist_y)
		{
			data->tmp.sdist_x += data->tmp.ddist_x;
			data->tmp.map_x += data->tmp.step_x;
			data->tmp.side = 0;
		}
		else
		{
			data->tmp.sdist_y += data->tmp.ddist_y;
			data->tmp.map_y += data->tmp.step_y;
			data->tmp.side = 1;
		}
		if (data->map.map[data->tmp.map_y][data->tmp.map_x] > 0)
			data->tmp.hit = 1;
	}
	(data->tmp.side == 0) ?\
	(data->tmp.walldist = (data->tmp.map_x - data->player.pos_x +\
	((1 - data->tmp.step_x) >> 1)) / data->tmp.raydir_x) : \
	(data->tmp.walldist = (data->tmp.map_y - data->player.pos_y +\
	((1 - data->tmp.step_y) >> 1)) / data->tmp.raydir_y);
}

void			core(t_data *data)
{
	data->tmp.x = 0;
	data->tmp.wall_x = 0.0;
	data->tmp.l_h = 0;
	while (data->tmp.x < WIDTH)
	{
		ft_distance(data);
		ft_hit(data);
		data->tmp.l_h = (int)((HEIGHT) / data->tmp.walldist);
		data->tmp.start = -(data->tmp.l_h >> 1) + H_H - data->player.camera.upd;
		data->tmp.end = (data->tmp.l_h >> 1) + H_H - data->player.camera.upd;
		(data->tmp.side == 0) ? (data->tmp.wall_x = data->player.pos_y +\
		data->tmp.walldist * data->tmp.raydir_y) : (data->tmp.wall_x =\
		data->player.pos_x + data->tmp.walldist *\
		data->tmp.raydir_x);
		data->tmp.wall_x -= floor(data->tmp.wall_x);
		data->tmp.text_x = (int)(data->tmp.wall_x * (double)data->tmp.gx);
		(data->tmp.side == 0 && data->tmp.raydir_x > 0) ? \
		(data->tmp.text_x = data->tmp.gx - data->tmp.text_x - 1) : 0;
		(data->tmp.side == 1 && data->tmp.raydir_y > 0) ? \
		(data->tmp.text_x = data->tmp.gy - data->tmp.text_x - 1) : 0;
		ft_hit_floor(data);
		ft_cf_viz(data);
		ft_draw_wall(data);
		data->tmp.x++;
	}
}

void			ft_core(t_data *data)
{
	while (data->process)
	{
		if (data->curent == NULL)
		{
			data->curent = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32,\
			0, 0, 0, 0);
			data->img = (uint32_t *)data->curent->pixels;
		}
		if (data->status == 1)
			ft_game_status(data);
		if (data->status == 2)
			ft_menu_status(data);
		SDL_BlitSurface(data->curent, NULL, data->screen, NULL);
		SDL_FreeSurface(data->curent);
		data->curent = NULL;
		SDL_UpdateWindowSurface(data->window);
	}
}

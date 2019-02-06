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

void		ft_left(t_data *data)
{
	double	cosinus;
	double	sinus;

	cosinus = cos(data->player.camera.speed);
	sinus = sin(data->player.camera.speed);
	data->tmp.olddir_x = data->player.camera.dir_x;
	data->player.camera.dir_x = data->player.camera.dir_x * cosinus - \
						data->player.camera.dir_y * sinus;
	data->player.camera.dir_y = data->tmp.olddir_x * sinus + \
						data->player.camera.dir_y * cosinus;
	data->tmp.oldplane_x = data->player.camera.plane_x;
	data->player.camera.plane_x = data->player.camera.plane_x * cosinus - \
						data->player.camera.plane_y * sinus;
	data->player.camera.plane_y = data->tmp.oldplane_x * sinus + \
							data->player.camera.plane_y * cosinus;
}

void		ft_right(t_data *data)
{
	double	cosinus;
	double	sinus;

	cosinus = cos(-data->player.camera.speed);
	sinus = sin(-data->player.camera.speed);
	data->tmp.olddir_x = data->player.camera.dir_x;
	data->player.camera.dir_x = data->player.camera.dir_x * cosinus - \
						data->player.camera.dir_y * sinus;
	data->player.camera.dir_y = data->tmp.olddir_x * sinus + \
						data->player.camera.dir_y * cosinus;
	data->tmp.oldplane_x = data->player.camera.plane_x;
	data->player.camera.plane_x = data->player.camera.plane_x * cosinus - \
						data->player.camera.plane_y * sinus;
	data->player.camera.plane_y = data->tmp.oldplane_x * sinus + \
						data->player.camera.plane_y * cosinus;
}

void		ft_forward(t_data *data)
{
	if (data->map.map[(int)data->player.pos_y]\
			[(int)(data->player.pos_x + data->player.camera.dir_x * \
				data->player.speed * 1.2)] == 0)
		data->player.pos_x += data->player.camera.dir_x * data->player.speed;
	if (data->map.map[(int)(data->player.pos_y + \
	data->player.camera.dir_y * data->player.speed * 1.2)]\
[(int)data->player.pos_x] == 0)
		data->player.pos_y += data->player.camera.dir_y * data->player.speed;
	if (data->keys[SDL_SCANCODE_D])
		ft_left(data);
	else if (data->keys[SDL_SCANCODE_A])
		ft_right(data);
}

void		ft_backward(t_data *data)
{
	if (data->map.map[(int)data->player.pos_y]\
			[(int)(data->player.pos_x - data->player.camera.dir_x * \
				data->player.speed)] == 0)
		data->player.pos_x -= data->player.camera.dir_x * data->player.speed;
	if (data->map.map[(int)(data->player.pos_y - data->player.camera.dir_y * \
	data->player.speed)][(int)data->player.pos_x] == 0)
		data->player.pos_y -= data->player.camera.dir_y * data->player.speed;
	if (data->keys[SDL_SCANCODE_D])
		ft_right(data);
	else if (data->keys[SDL_SCANCODE_A])
		ft_left(data);
}

void		ft_move(t_data *data)
{
	if (data->keys[SDL_SCANCODE_W])
		ft_forward(data);
	else if (data->keys[SDL_SCANCODE_S])
		ft_backward(data);
	else if (data->keys[SDL_SCANCODE_D])
		ft_left(data);
	else if (data->keys[SDL_SCANCODE_A])
		ft_right(data);
	else if (data->keys[SDL_SCANCODE_UP])
		data->player.camera.upd -= 10;
	else if (data->keys[SDL_SCANCODE_DOWN])
		data->player.camera.upd += 10;
}

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

int				ft_check(t_card *card, char **map, int n)
{
	if ((*card->line == '\0' || *card->line == '\n'
		|| n == card->cwidth) && ft_validval(map))
		return (1);
	return (0);
}

void			ft_zooming(t_data *data)
{
	if (data->keys[SDL_SCANCODE_KP_PLUS])
		data->player.camera.zooming += 0.1;
	else if (data->keys[SDL_SCANCODE_KP_MINUS])
		(data->player.camera.zooming > 1) ? \
		(data->player.camera.zooming -= 0.1) : 0;
}

void			ft_game_keys(t_data *data)
{
	if (SDL_PollEvent(&data->keyhook))
	{
		data->keys = SDL_GetKeyboardState(NULL);
		if ((data->keyhook.type == SDL_QUIT)
			|| data->keys[SDL_SCANCODE_ESCAPE])
			data->process = 0;
		else if (data->keyhook.type == SDL_QUIT)
			data->process = 0;
	}
}

void			ft_game_status(t_data *data)
{
	ft_game_keys(data);
	core(data);
	(data->keys[SDL_SCANCODE_W] || \
	data->keys[SDL_SCANCODE_S] || \
	data->keys[SDL_SCANCODE_D] || \
	data->keys[SDL_SCANCODE_A] || \
	data->keys[SDL_SCANCODE_UP] || \
	data->keys[SDL_SCANCODE_DOWN]) ? ft_move(data) : 0;
	(data->keys[SDL_SCANCODE_KP_PLUS] || \
	data->keys[SDL_SCANCODE_KP_MINUS]) ? ft_zooming(data) : 0;
}

void			ft_key_down(t_data *data)
{
	if (data->waithook.key.keysym.scancode == SDL_SCANCODE_DOWN || \
		data->waithook.key.keysym.scancode == SDL_SCANCODE_RETURN || \
		data->waithook.key.keysym.scancode == SDL_SCANCODE_UP)
	{
		if (data->welcome.chosen[0] == 0)
		{
			printf("CHOSEN EXIT\n");
			data->welcome.chosen[0] = 1;
			data->welcome.chosen[1] = 0;
		}
		else if (data->welcome.chosen[0] == 1)
		{
			printf("CHOSEN START\n");
			data->welcome.chosen[0] = 0;
			data->welcome.chosen[1] = 1;
		}
		if (data->waithook.key.keysym.scancode == SDL_SCANCODE_RETURN)
		{
			printf("Executed");
			if (data->welcome.chosen[0] == 1)
				data->status = 1;
			if (data->welcome.chosen[1] == 1)
				data->process = 0;
		}
	}
}

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

void			ft_menu_keys(t_data *data)
{
	if (SDL_WaitEvent(&data->waithook))
	{
		data->keys = SDL_GetKeyboardState(NULL);
		if (data->waithook.type == SDL_QUIT || \
		data->waithook.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			data->process = 0;
		if (data->keys[SDL_SCANCODE_BACKSPACE])
			data->status = 1;
		else if (data->waithook.type == SDL_KEYDOWN)
			ft_key_down(data);
	}
}

void			ft_options(t_data *data)
{
	(data->welcome.chosen[0] == 1) ? \
	SDL_BlitSurface(data->welcome.words[0], NULL, data->curent,\
	&data->welcome.loc[0]) : SDL_BlitSurface(data->welcome.words[1],\
	NULL, data->curent, &data->welcome.loc[0]);
	(data->welcome.chosen[1] == 1) ? \
	SDL_BlitSurface(data->welcome.words[2], NULL, data->curent,\
	&data->welcome.loc[1]) : SDL_BlitSurface(data->welcome.words[3],\
	NULL, data->curent, &data->welcome.loc[1]);
}

void			ft_menu_status(t_data *data)
{
	SDL_BlitSurface(data->scaled, NULL, data->curent, NULL);
	ft_menu_keys(data);
	ft_options(data);
}

void			ft_checkout(SDL_Surface *main, t_uin *uin)
{
	uin->tex_col = main->pixels;
	uin->scaled = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
	uin->scr_col = uin->scaled->pixels;
}

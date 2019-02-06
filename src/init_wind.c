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

int				ft_init_images(t_data *data)
{
	(!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))) ? ft_error_init_images() : 0;
	(ft_malloc_images(data)) ? ft_error_images() : 0;
	return (0);
}

int				ft_init_audios(t_data *data)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_error_audios();
	data->music.path = "./resources/music/";
	return (0);
}

void			ft_init_color(t_data *data)
{
	data->welcome.color[0].r = 255;
	data->welcome.color[0].g = 255;
	data->welcome.color[0].b = 255;
	data->welcome.color[1].r = 255;
	data->welcome.color[1].g = 0;
	data->welcome.color[1].b = 0;
}

int				ft_init_ttf(t_data *data)
{
	data->welcome.font = TTF_OpenFont("./resources/fonts/wolf.ttf", 40);
	data->welcome.lab[0] = "Go! Go! Go!";
	data->welcome.lab[1] = "Exit";
	ft_init_color(data);
	data->welcome.words[0] = TTF_RenderText_Solid(data->welcome.font,\
	data->welcome.lab[0], data->welcome.color[0]);
	data->welcome.words[1] = TTF_RenderText_Solid(data->welcome.font, \
	data->welcome.lab[0], data->welcome.color[1]);
	data->welcome.words[2] = TTF_RenderText_Solid(data->welcome.font, \
	data->welcome.lab[1], data->welcome.color[0]);
	data->welcome.words[3] = TTF_RenderText_Solid(data->welcome.font, \
	data->welcome.lab[1], data->welcome.color[1]);
	data->welcome.chosen[0] = 0;
	data->welcome.chosen[1] = 1;
	data->welcome.loc[0].x = WIDTH -\
	200 - data->welcome.words[0]->clip_rect.w;
	data->welcome.loc[0].y = HEIGHT -\
	100 - data->welcome.words[0]->clip_rect.h;
	data->welcome.loc[1].x = WIDTH -\
	100 - data->welcome.words[1]->clip_rect.w;
	data->welcome.loc[1].y = HEIGHT -\
	50 - data->welcome.words[1]->clip_rect.h;
	ft_main_scaled(data);
	return (0);
}

void			ft_init_window(t_data *data)
{
	(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)\
	? ft_error_init_window() : 0;
	(TTF_Init() == -1) ? ft_error_init_ttf() : 0;
	(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) ?\
	ft_error_render_quality() : 0;
	data->window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED,\
	SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	(data->window == NULL) ? ft_error_init_window() : (data->screen =\
	SDL_GetWindowSurface(data->window));
	(ft_init_audios(data)) ? ft_error_audios() : 0;
	(ft_init_images(data)) ? ft_error_images() : 0;
	(ft_init_ttf(data)) ? ft_error_ttf() : 0;
}

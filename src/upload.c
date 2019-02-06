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

void				*ft_upload_img(char *path)
{
	SDL_Surface		*opt;
	SDL_Surface		*tmp;
	SDL_PixelFormat	format;

	format.BitsPerPixel = 32;
	format.BytesPerPixel = 4;
	format.palette = NULL;
	format.Rmask = 0;
	format.Gmask = 0;
	format.Bmask = 0;
	format.Amask = 0;
	tmp = NULL;
	opt = NULL;
	if ((tmp = IMG_Load(path)) != NULL)
		opt = SDL_ConvertSurface(tmp, &format, 0);
	else
		ft_error_image_upload();
	SDL_FreeSurface(tmp);
	return (opt);
}

void				ft_walls_textures(t_data *data)
{
	int i;

	i = 0;
	data->walls.texture[0] = ft_upload_img("./resources/wall/one.png");
	data->walls.texture[1] = ft_upload_img("./resources/wall/two.png");
	data->walls.texture[2] = ft_upload_img("./resources/wall/three.png");
	data->walls.texture[3] = ft_upload_img("./resources/wall/four.png");
	data->walls.texture[4] = ft_upload_img("./resources/wall/five.png");
	data->walls.texture[5] = ft_upload_img("./resources/wall/six.png");
	data->walls.texture[6] = ft_upload_img("./resources/wall/seven.png");
	data->walls.texture[7] = ft_upload_img("./resources/wall/eight.png");
	while (i < 8)
	{
		if (data->walls.texture[i] == NULL)
			ft_error_texture();
		i++;
	}
}

void				ft_floor_textures(t_data *data)
{
	data->floor.texture[0] = ft_upload_img("./resources/floor/one.png");
}

void				ft_ceiling_textures(t_data *data)
{
	data->ceiling.texture[0] = ft_upload_img("./resources/ceiling/one.png");
}

int					ft_malloc_images(t_data *data)
{
	data->walls.texture = malloc(sizeof(SDL_Surface) * data->walls.quantity);
	data->ceiling.texture = malloc(sizeof(SDL_Surface) *\
	data->ceiling.quantity);
	data->floor.texture = malloc(sizeof(SDL_Surface) * data->floor.quantity);
	(!data->walls.texture &&\
	!data->ceiling.texture &&\
	!data->floor.texture) ?\
		ft_error_malloc() : 0;
	ft_walls_textures(data);
	ft_floor_textures(data);
	ft_ceiling_textures(data);
	return (0);
}

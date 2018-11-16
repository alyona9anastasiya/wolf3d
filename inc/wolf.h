/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:04:22 by avatseba          #+#    #+#             */
/*   Updated: 2018/11/16 20:02:12 by avatseba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_timer.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"

# include <libft.h>

# define WIDTH 700
# define HEIGHT 700

struct				t_card
{
	int				fd;
	int				**map;
	int				cwidth;
	int				cheight;
	char			*line;
};	

struct				t_data
{

	SDL_Window		*window;
	SDL_Surface		*screen;
	SDL_Event		keyhook;
	const uint8_t	*keys;
	uint32_t		*img;
};


#endif

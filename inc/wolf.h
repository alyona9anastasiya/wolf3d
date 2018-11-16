/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:04:22 by avatseba          #+#    #+#             */
/*   Updated: 2018/11/16 23:47:24 by ylisyak          ###   ########.fr       */
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
# include <stdio.h>
# define WIDTH 700
# define HEIGHT 700

typedef struct		s_card
{
	int				fd;
	int				**map;
	int				cwidth;
	int				cheight;
	char			*line;
}					t_card;	

typedef struct		s_map
{
	int				map_width;
	int				map_height;
	int				**map;

}					t_map;

typedef struct		s_data
{

	SDL_Window		*window;
	SDL_Surface		*screen;
	SDL_Event		keyhook;

	t_map			map;
	const uint8_t	*keys;
	uint32_t		*img;
}					t_data;
//  ERROR STUFF
void			ft_get_out(void);
void			ft_error_fd(void);
void			ft_error_size(void);
void			ft_error_long(void);
void			ft_error_malloc(void);
void			ft_error_notdigit(void);
void			ft_error_resolution(void);
void			ft_error_bufferization(void);
// VALIDATION PART
int				ft_define_correct(void);
int				ft_map_size_review(t_card *card);
int				ft_validation(char *file, t_data *data);
int				ft_correct_size(char *file, t_card *card);

int				ft_parsing(char *file, t_data *data);
//	LIBRUARY STUFF
int				ft_nbr_len(int nbr);
//	MEMORY
int				ft_card_malloc(t_data *data, t_card *card);
#endif

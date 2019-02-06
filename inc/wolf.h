/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avatseba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:04:22 by avatseba          #+#    #+#             */
/*   Updated: 2018/11/24 18:55:12 by avatseba         ###   ########.fr       */
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
# include <../library/libft/get_next_line.h>
# define WIDTH 700
# define HEIGHT 700
# define H_H	(WIDTH / 2)

typedef struct		s_card
{
	int				fd;
	int				**map;
	int				cwidth;
	int				cheight;
	char			*line;
}					t_card;

typedef struct		s_uin
{
	uint32_t		*tex_col;
	uint32_t		*scr_col;
	uint32_t		tmp_color;
	SDL_Surface		*scaled;

}					t_uin;

typedef struct		s_map
{
	int				map_width;
	int				map_height;
	int				**map;

}					t_map;

typedef struct		s_welcome
{
	SDL_Rect		loc[2];
	TTF_Font		*font;
	SDL_Color		color[2];
	SDL_Surface		*words[4];
	char			*lab[2];
	int				chosen[2];
}					t_welcome;

typedef struct		s_camera
{
	int				upd;
	double			zooming;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			speed;
}					t_camera;

typedef struct		s_player
{
	t_camera		camera;
	double			pos_x;
	double			pos_y;
	double			current_speed;
	double			speed;
}					t_player;

typedef struct		s_music
{
	int				play;
	int				pause;
	int				stop;
	char			*path;
	Mix_Music		*track;
}					t_music;

typedef struct		s_img
{
	int				quantity;
	SDL_Surface		**texture;
}					t_img;

typedef struct		s_tmp
{
	int				x;
	int				y;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				gx;
	int				gy;
	int				hit;
	int				l_h;
	int				side;
	int				start;
	int				end;
	int				corrector;
	int				cof_s;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			camera;
	double			sdist_x;
	double			sdist_y;
	double			ddist_x;
	double			ddist_y;
	double			wall_x;
	double			walldist;
	double			tmpdistwall;
	double			tmpdistplayer;
	double			floor_x;
	double			floor_y;
	int				floortex_x;
	int				floortex_y;
	double			raydir_x;
	double			raydir_y;
	double			olddir_x;
	double			olddir_y;
	double			oldplane_x;
	double			oldplane_y;
	int				text_x;
	int				text_y;
	uint32_t		*text_pix;
	uint32_t		color_pix;
}					t_tmp;

typedef struct		s_data
{
	int				process;
	int				status;
	t_music			music;
	t_player		player;
	t_img			walls;
	t_img			ceiling;
	t_img			floor;
	t_welcome		welcome;
	SDL_Window		*window;
	SDL_Surface		*screen;
	SDL_Surface		*curent;
	SDL_Surface		*scaled;
	SDL_Event		keyhook;
	SDL_Event		waithook;
	t_map			map;
	t_tmp			tmp;
	const uint8_t	*keys;
	uint32_t		*img;
}					t_data;

void				ft_get_out(void);
void				ft_error_fd(void);
void				ft_error_size(void);
void				ft_error_folder(void);
void				ft_error_long(void);
void				ft_error_hex(void);
void				ft_error_minus(void);
void				ft_error_image_upload(void);
void				ft_error_out_from_map(void);
void				ft_error_in_wall(void);
void				ft_error_malloc(void);
void				ft_error_ttf(void);
void				ft_error_render_quality(void);
void				ft_error_init_images(void);
void				ft_error_init_ttf(void);
void				ft_error_init_window(void);
void				ft_error_audios(void);
void				ft_error_images(void);
void				ft_error_notdigit(void);
void				ft_error_resolution(void);
void				ft_error_bufferization(void);
void				ft_error_texture(void);

int					ft_define_correct(void);
int					ft_map_size_review(t_card *card);
int					ft_validation(char *file, t_data *data);
int					ft_correct_size(char *file, t_card *card);
int					ft_parsing(char *file, t_data *data);

int					ft_nbr_len(int nbr);
void				ft_main_scaled(t_data *data);
int					ft_malloc_images(t_data *data);
void				ft_game_status(t_data *data);
void				ft_menu_status(t_data *data);
void				ft_move(t_data *data);
void				ft_key_down(t_data *data);

int					ft_card_malloc(t_data *data, t_card *card);
void				ft_core(t_data *data);
void				core(t_data *data);
void				ft_cf_viz(t_data *data);
void				ft_hit_floor(t_data *data);
void				ft_draw_wall(t_data *data);
int					ft_create_map(char *file, t_data *data);
void				ft_correction(t_data *data);
void				ft_init_data(t_data *data);
void				ft_init_player(t_player *player);
void				ft_place_holder_player_map(t_data *data);
void				ft_init_window(t_data *data);
void				ft_count_etax(t_card *card, char **map, int *etax);
int					ft_validval(char **maps);
void				ft_filler(t_data *data, char *iter, int *x, int y);
int					ft_check(t_card *card, char **map, int n);
void				ft_checkout(SDL_Surface *main, t_uin *uin);

#endif

/*
** my_struct.h for my_struct in /home/fisun_s/rendu/MUL_2014_wolf3d
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sun Dec 21 08:08:33 2014 Fisun Sergii
** Last update Sun Dec 21 21:37:27 2014 Fisun Sergii
*/

#ifndef MY_STRUCT_H_
# define MY_STRUCT_H_

# define	PI (3.1415)
# define	RAD(n) (n * PI / 180)
# define	WIN_X 1000
# define	WIN_Y 768
# define	MAP_POS (WIN_Y - 180)
# define	P 1
# define	UP 65362
# define	DOWN 65364
# define	LEFT 65361
# define	RIGHT 65363
# define	Z 122
# define	Q 113
# define	X 100
# define	S 115
# define	M 109
# define	L 108
# define	O 111
# define	U 117
# define	I 105
# define	W1 38
# define	W2 233
# define	W3 34
# define	W4 39
# define	ZOOM 101
# define	PLUS 61
# define	MINUS 41
# define	A 97
# define	U 117
# define	MENU 178

typedef struct		s_wolf
{
  struct s_pos		*pos;
  struct s_image	*img;
  struct s_win		*win;
  struct s_button	*button;
  struct s_map		*maps;
  struct s_image	*mmap;
  struct s_tex		*tex;
  struct s_tex		*weapon;
  struct s_tex		*sky;
  struct s_sprite	*sprite;
  int			hy;
  int			wy;
  int			maps_n;
  int			c_map;
  int			h;
  int			floorn;
  int			speed;
}			t_wolf;

typedef struct		s_tex
{
  void			*img_ptr;
  unsigned char		*data;
  int			width;
  int			height;
  int			line_size;
  int			bbp;
  int			endian;
}			t_tex;

typedef struct		s_map
{
  char			*name;
  int			height;
  int			width;
  char			**map;
}			t_map;

typedef struct		s_floor
{
  int			tx;
  int			ty;
  float			dist;
}			t_floor;

typedef struct		s_button
{
  char			up;
  char			down;
  char			left;
  char			right;
  char			light;
  int			time;
  char			anim_state;
  char			fire;
  int			cw;
  char			waza_mode;
  int			t;
  char			screen;
  char			mouse_press;
  int			mouse_x;
  int			mouse_y;
}			t_button;

typedef struct		s_pos
{
  float			D;
  float			k;
  float			x;
  float			y;
  int			angle;
  float			cosa;
  float			sina;
  float			x1;
  float			y1;
  float			posx;
  float			posy;
  char			side;
  int			tx;
  int			ty;
  int			ta_start;
}			t_pos;

typedef struct		s_image
{
  void			*img_ptr;
  unsigned char		*data;
  int			bbp;
  int			line_size;
  int			endian;
}			t_image;

typedef struct		s_win
{
  void			*win_ptr;
  void			*mlx_ptr;
}			t_win;

typedef	struct		s_params
{
  int			x1;
  int			y1;
  int			y2;
}			t_params;

char		*my_get_nextline(char *, int);
char		*my_read_to_str(char *);
char		**my_nbr_to_wordtab(char *);
char		*my_read_to_str(char *);
int		**get_int_tab(char *, t_params *);
int		**first_step(int, char *, t_params *);
int		**str_to_int_tab(int **, char *);
void		calc_X_Y(t_pos *, int);
float		calc_k(int, float, float);
int		calc_x(float, float, float);
float		calc_k_x(t_pos *, t_map *);
float		calc_k_y(t_pos *, float, t_map *);
char 		**str_to_char_tab(char **, char *, t_map *);
t_map		get_map(char *, char *);
char		*my_strcat(char *, char *);
char		*my_strdup(char *);
void		make_mmap(t_image *, t_wolf *);
void		get_pos_mmap(t_image *, t_wolf *);
void		init_mmap(t_image *);
void		make_cube(t_image *, int x, int y, unsigned int);
void		get_maps(t_wolf *);
void		drow_line(t_wolf *, t_params, int, int);
int		my_put_pixel_image(t_image *, int, int, unsigned int);
int		my_getnbr(char *);
int		my_strlen(char *);
void		read_tex(t_win *, t_tex *, char *);
int		get_texX(t_pos *, float, int);
void		draw_wolf(t_wolf *, int, int, int);
void		get_tex(t_wolf *);
void		read_tex(t_win *, t_tex *, char *);
void		init_wolf(t_wolf *);
void		init_pos(t_wolf *);
int		gere(t_wolf *);
int		gere_keypress(int, t_wolf *);
int		gere_keyrelease(int, t_wolf *);
void		calc_and_draw(t_wolf *);
int		draw(t_wolf *, int, int, int, int);
void		draw_top(t_wolf *, t_floor, int, int);
void		draw_bot(t_wolf *, t_floor, int, int);
void		floor_casting(t_wolf *, int, int);
int		height_define(char *);
int		width_define(char *, t_map *);
char		**get_char_tab(char *, t_map *);
void		img_to_img(t_image *, t_tex *, int, int);
void		draw_sky(t_wolf *, t_params);
void		move_forward(t_wolf *);
void		move_back(t_wolf *);
void		get_weapons(t_wolf *);
void		mat_rotate(float *, float *, int);
int		drawo(t_wolf *, int);
int		gere_expose(t_wolf *);
int		button_press(int, int, int, t_wolf *);
void		hooks(t_wolf *);
int		screen_define(char, void *, void *, t_wolf *);

#endif	/* !MY_STRUCT_H_ */

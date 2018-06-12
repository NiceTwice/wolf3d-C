/*
** init_wolf.c for init_wolf in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Wed Dec 10 00:08:21 2014 Fisun Sergii
** Last update Sun Dec 21 23:29:22 2014 Fisun Sergii
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"mlx.h"
#include	"my_struct.h"

void		get_tex(t_wolf *wolf)
{
  t_tex		*tex;
  t_tex		*sky;

  if ((sky = malloc(sizeof(t_tex) * 2)) == NULL)
    exit(write(1, "Error\n", 6));
  if ((tex = malloc(sizeof(t_tex) * 8)) == NULL)
    exit(write(1, "Error\n", 6));
  read_tex(wolf->win, &tex[0], "textures/sol_herbe.xpm");
  read_tex(wolf->win, &tex[1], "textures/mur9.xpm");
  read_tex(wolf->win, &tex[2], "textures/mur2.xpm");
  read_tex(wolf->win, &tex[3], "textures/mur7.xpm");
  read_tex(wolf->win, &tex[4], "textures/mur3.xpm");
  read_tex(wolf->win, &tex[5], "textures/guervi_a.xpm");
  read_tex(wolf->win, &tex[6], "textures/waza.xpm");
  read_tex(wolf->win, &tex[7], "textures/usage.xpm");
  read_tex(wolf->win, &tex[8], "textures/menu.xpm");
  wolf->tex = tex;
  read_tex(wolf->win, &sky[0], "textures/ciel2.xpm");
  read_tex(wolf->win, &sky[1], "textures/FISUN.xpm");
  wolf->sky = sky;
}

void		get_weapons(t_wolf *wolf)
{
  t_tex		*weapon;

  if ((weapon = malloc(sizeof(t_tex) * 7)) == NULL)
    exit(write(1, "Error\n", 6));
  read_tex(wolf->win, &weapon[0], "textures/ak_47.xpm");
  read_tex(wolf->win, &weapon[1], "textures/awp.xpm");
  read_tex(wolf->win, &weapon[2], "textures/lampe.xpm");
  read_tex(wolf->win, &weapon[3], "textures/piedbiche.xpm");
  read_tex(wolf->win, &weapon[4], "textures/viseur1.xpm");
  read_tex(wolf->win, &weapon[5], "textures/cible1.xpm");
  read_tex(wolf->win, &weapon[6], "textures/fire.xpm");
  wolf->weapon = weapon;
}

void		read_tex(t_win *win, t_tex *tex, char *path)
{
  if ((tex->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, path,
					    &tex->width, &tex->height)) == NULL)
    exit(write(1, "Error\n", 6));
  tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bbp,
				&tex->line_size, &tex->endian);
}

void		init_wolf(t_wolf *wolf)
{
  if ((wolf->button = malloc(sizeof(t_button))) == NULL)
    exit(write(1, "Error\n", 6));
  if ((wolf->pos = malloc(sizeof(t_pos))) == NULL)
    exit(write(1, "Error\n", 6));
  if ((wolf->win = malloc(sizeof(t_win))) == NULL)
    exit(write(1, "Error\n", 6));
  if ((wolf->img = malloc(sizeof(t_image))) == NULL)
    exit(write(1, "Error\n", 6));
  if ((wolf->mmap = malloc(sizeof(t_image))) == NULL)
    exit(write(1, "Error\n", 6));
  if ((wolf->win->mlx_ptr = mlx_init()) == NULL)
    exit(write(1, "Error\n", 6));
  wolf->win->win_ptr = mlx_new_window(wolf->win->mlx_ptr,
                                    WIN_X, WIN_Y, "wolf3d fisun_s");
  mlx_string_put(wolf->win->mlx_ptr, wolf->win->win_ptr,
                 (WIN_X / 2), (WIN_Y / 2), 0xFFFFFF, "Loading...");
  wolf->img->img_ptr = mlx_new_image(wolf->win->mlx_ptr, WIN_X, WIN_Y);
  wolf->img->data = mlx_get_data_addr(wolf->img->img_ptr, &wolf->img->bbp,
  				      &wolf->img->line_size,
  				      &wolf->img->endian);
  wolf->mmap->img_ptr = mlx_new_image(wolf->win->mlx_ptr, 180, 180);
  wolf->mmap->data = mlx_get_data_addr(wolf->mmap->img_ptr, &wolf->mmap->bbp,
  				       &wolf->mmap->line_size,
  				       &wolf->mmap->endian);
}

void		init_pos(t_wolf *wolf)
{
  wolf->pos->D = 0.5;
  wolf->c_map = 0;
  wolf->button->up = 0;
  wolf->button->down = 0;
  wolf->button->left = 0;
  wolf->button->right = 0;
  wolf->button->light = 1;
  wolf->button->screen = 0;
  wolf->button->time = 250;
  wolf->button->anim_state = 1;
  wolf->button->fire = 0;
  wolf->pos->x = 1.5;
  wolf->pos->y = 1.5;
  wolf->pos->angle = 0;
  wolf->floorn = 0;
  wolf->hy = WIN_Y / 2;
  wolf->wy = WIN_Y;
  wolf->button->waza_mode = 0;
  wolf->button->cw = 0;
  wolf->speed = 20;
}

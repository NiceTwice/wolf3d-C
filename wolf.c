/*
** wolf.c for wolf in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Thu Dec  4 12:27:24 2014 Fisun Sergii
** Last update Mon Dec 22 00:03:34 2014 Fisun Sergii
*/

#include	<stdlib.h>
#include	<math.h>
#include	<stdio.h>
#include	<X11/xpm.h>
#include	"mlx.h"
#include	"my_struct.h"
#include	"mlx_int.h"

void		main_draw(t_wolf *wall)
{
  int		x;
  int		texX;
  int		texn;

  x = 0;
  while (x <= WIN_X)
    {
      calc_X_Y(wall->pos, x);
      wall->pos->k = calc_k_x(wall->pos, &(wall->maps[wall->c_map]));
      wall->h = WIN_Y / (2 * wall->pos->k);
      texn = wall->maps[wall->c_map].map[wall->pos->tx][wall->pos->ty];
      if (wall->button->waza_mode != 0)
	{
	  if (wall->button->waza_mode == 1)
	    wall->button->t = 6;
	  else
	    wall->button->t = 5;
	  texn = wall->button->t;
	  wall->floorn = wall->button->t;
	}
      texX = get_texX(wall->pos, wall->pos->k, wall->tex[texn].width);
      draw_wolf(wall, x, texn, texX);
      x++;
    }
}

void		put_weapons(t_wolf *wall)
{
  if (wall->button->fire == 1)
    {
      img_to_img(wall->img, &wall->weapon[6], 600, 475);
      wall->pos->D = 0.5;
    }
  if (wall->pos->D != 0.5 && wall->button->cw == 1)
    img_to_img(wall->img, &wall->weapon[5], 0, 0);
  else
    img_to_img(wall->img, &wall->weapon[wall->button->cw],
  	       (WIN_X - wall->weapon->width), (WIN_Y - wall->button->time));
  if (wall->button->cw == 0)
    img_to_img(wall->img, &wall->weapon[4], 475, 359);
}

void		calc_and_draw(t_wolf *wall)
{
  void		*mlx_ptr;
  void		*win_ptr;

  mlx_ptr = wall->win->mlx_ptr;
  win_ptr = wall->win->win_ptr;
  wall->pos->ta_start = wall->sky[(int)wall->button->light].width /
    360 * (360 - wall->pos->angle);
  main_draw(wall);
  put_weapons(wall);
  mlx_put_image_to_window(mlx_ptr, win_ptr, wall->img->img_ptr, 0, 0);
}

int		main()
{
  t_wolf	put;

  init_wolf(&put);
  get_maps(&put);
  init_pos(&put);
  get_tex(&put);
  get_weapons(&put);
  hooks(&put);
  return (0);
}

/*
** gere_buttons.c for gere_buttons in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Wed Dec 10 00:16:51 2014 Fisun Sergii
** Last update Sun Dec 21 22:48:51 2014 Fisun Sergii
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my_struct.h"
#include	"mlx.h"

int		gere(t_wolf *put)
{
  void		*win_ptr;
  void		*mlx_ptr;

  win_ptr = put->win->win_ptr;
  mlx_ptr = put->win->mlx_ptr;
  usleep(500);
  if (screen_define(put->button->screen, mlx_ptr, win_ptr, put) == 1)
    return (0);
  if (put->button->anim_state == 0 && ((put->button->time += 25) % 250) == 0)
    put->button->anim_state = 1;
  if (put->button->left == 1 && (put->pos->angle += 4) >= 360)
    put->pos->angle = 0;
  if (put->button->right == 1 && (put->pos->angle -= 4) <= 0)
    put->pos->angle = 360;
  if (put->button->up == 1)
    move_forward(put);
  else if (put->button->down == 1)
    move_back(put);
  usleep(500);
  calc_and_draw(put);
  make_mmap(put->mmap, put);
  if (put->button->fire == 1)
    put->button->fire = 0;
  return (0);
}

int		gere_keypress(int key, t_wolf *wolf)
{
  if (key == PLUS && --(wolf->speed) < 2)
    wolf->speed = 2;
  else if (key == A && (wolf->button->cw == 0 ||
			wolf->button->cw == 1) && ++wolf->button->fire > 1)
    wolf->button->fire = 0;
  else if (key == MINUS && ++(wolf->speed) > 40)
    wolf->speed = 40;
  else if (key == 65307)
    exit(1);
  else if (key == UP || key == Z)
    wolf->button->up = 1;
  else if (key == DOWN || key == S)
    wolf->button->down = 1;
  else if (key == LEFT || key == Q)
    wolf->button->left = 1;
  else if (key == RIGHT || key == X)
    wolf->button->right = 1;
  return (0);
}

void		choose_weapon(int key, t_wolf *wolf)
{
  wolf->button->anim_state = 0;
  wolf->button->time = 0;
  if (key == W1)
    wolf->button->cw = 0;
  else if (key == W2)
    wolf->button->cw = 1;
  else if (key == W3)
    wolf->button->cw = 2;
  else if (key == W4)
    wolf->button->cw = 3;
  wolf->pos->D = 0.5;
}

void		check_buttons(int key, t_wolf *wolf)
{
  int		x;
  int		y;

  if (key == O && ++wolf->floorn > 6)
    wolf->floorn = 0;
  else if (key == L && ++wolf->button->light > 1)
    wolf->button->light = 0;
  else if (key == 109 && ++wolf->c_map >= 0)
    {
      wolf->pos->x = 1.5;
      wolf->pos->y = 1.5;
      if (wolf->c_map == wolf->maps_n)
      	wolf->c_map = 0;
    }
  else if (key == A && wolf->button->cw == 3)
    {
      x = wolf->pos->x + (wolf->pos->cosa / 2);
      y = wolf->pos->y + (wolf->pos->sina / 2);
      if (x > 0 && y > 0 && y < (wolf->maps[wolf->c_map].width - 1)
	  && x < (wolf->maps[wolf->c_map].height - 1))
	wolf->maps[wolf->c_map].map[x][y] = 0;
    }
}

int		gere_keyrelease(int key, t_wolf *wolf)
{
  if (key == W1 || key == W2 || key == W3 || key == W4)
    choose_weapon(key, wolf);
  else if (key == MENU)
    wolf->button->screen = 0;
  else if (key == U && ++wolf->button->waza_mode > 2)
    {
      wolf->button->waza_mode = 0;
      wolf->floorn = 0;
    }
  else if (key == ZOOM && wolf->button->cw == 1 && wolf->pos->D == 0.5)
    wolf->pos->D = 2;
  else if (key == ZOOM && wolf->button->cw == 1 && wolf->pos->D == 2.0)
    wolf->pos->D = 0.5;
  else if (key == UP || key == Z)
    wolf->button->up = 0;
  else if (key == DOWN || key == S)
    wolf->button->down = 0;
  else if (key == LEFT || key == Q)
    wolf->button->left = 0;
  else if (key == RIGHT || key == X)
    wolf->button->right = 0;
  check_buttons(key, wolf);
  return (0);
}

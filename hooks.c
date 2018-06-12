/*
** hooks.c for hooks in /home/fisun_s/rendu/MUL_2014_wolf3d
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sat Dec 20 14:45:22 2014 Fisun Sergii
** Last update Sun Dec 21 22:40:19 2014 Fisun Sergii
*/

#include	<stdlib.h>
#include	"mlx_int.h"
#include	"mlx.h"
#include	"my_struct.h"

int	gere_expose(t_wolf *wolf)
{
  void	*win_ptr;
  void	*mlx_ptr;

  win_ptr = wolf->win->win_ptr;
  mlx_ptr = wolf->win->mlx_ptr;
  if (wolf->button->screen == 2)
    mlx_put_image_to_window(mlx_ptr, win_ptr, wolf->tex[7].img_ptr, 0, 0);
  else if (wolf->button->screen == 0)
    mlx_put_image_to_window(mlx_ptr, win_ptr, wolf->tex[8].img_ptr, 0, 0);
  else if (wolf->button->screen == 1)
    {
      mlx_put_image_to_window(mlx_ptr, win_ptr, wolf->img->img_ptr, 0, 0);
      mlx_put_image_to_window(mlx_ptr, win_ptr,
			      wolf->mmap->img_ptr, 0, MAP_POS);
    }
  return (0);
}

int	button_press(int button, int x, int y, t_wolf *wolf)
{
  wolf->button->mouse_press = 1;
  if (button == 1 && wolf->button->screen == 0)
    {
      if (x > 400 && x < 590 && y > 232 && y < 290)
	wolf->button->screen = 1;
      else if (x > 410 && y > 350 && x < 560 && y < 410)
	wolf->button->screen = 2;
      else if (x > 463 && x < 550 && y > 460 && y < 510)
	exit(1);
    }
  return (0);
}

int	button_release(t_wolf *wolf)
{
  wolf->button->mouse_press = 0;
  return (0);
}

int	mouse_pos(int x, int y, t_wolf *wolf)
{
  if (wolf->button->mouse_press == 1)
    {
      if ((wolf->button->mouse_x - x) > 0)
	{
	  wolf->pos->angle = wolf->pos->angle + 3;
	  if (wolf->pos->angle >= 360)
	    wolf->pos->angle = 0;
	}
      else if ((wolf->button->mouse_x - x) < 0)
	{
	  wolf->pos->angle = wolf->pos->angle - 3;
	  if (wolf->pos->angle <= 0)
	    wolf->pos->angle = 360;
	}
    }
  wolf->button->mouse_x = x;
  wolf->button->mouse_y = y;
  return (0);
}

void	hooks(t_wolf *wolf)
{
  mlx_expose_hook(wolf->win->win_ptr, &gere_expose, wolf);
  mlx_hook(wolf->win->win_ptr, ButtonRelease, ButtonReleaseMask,
	   &button_release, wolf);
  mlx_hook(wolf->win->win_ptr, MotionNotify,
	   PointerMotionMask, &mouse_pos, wolf);
  mlx_hook(wolf->win->win_ptr, ButtonPress,
	   ButtonPressMask, &button_press, wolf);
  mlx_hook(wolf->win->win_ptr, KeyPress,
	   KeyPressMask, gere_keypress, wolf);
  mlx_hook(wolf->win->win_ptr, KeyRelease,
           KeyReleaseMask, gere_keyrelease, wolf);
  mlx_loop_hook(wolf->win->mlx_ptr, &gere, wolf);
  mlx_loop(wolf->win->mlx_ptr);
}

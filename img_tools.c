/*
** img_tools.c for img_tools in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Thu Dec 11 02:31:27 2014 Fisun Sergii
** Last update Sun Dec 21 22:38:22 2014 Fisun Sergii
*/

#include	"mlx.h"
#include	"my_struct.h"

void		img_to_img(t_image *dest, t_tex *src, int x, int y)
{
  int		x1;
  int		dx;
  int		y1;
  int		dpixel;
  int		spixel;

  y1 = -1;
  while ((x1 = (-1)) >= -1 && ++y1 < src->height)
    {
      dx = x - 1;
      while (++x1 < src->width && ++dx >= x)
	  if (dx >= 0 && y >= 0 && dx <= WIN_X && y <= WIN_Y)
	    {
	      dpixel = (dest->line_size * y) + (dx * 4);
	      spixel = (src->line_size * y1) + (x1 * 4);
	      if (src->data[spixel] != 255 ||
		  src->data[spixel + 1] != 255 || src->data[spixel + 2] != 255)
		{
		  dest->data[dpixel++] = src->data[spixel++];
		  dest->data[dpixel++] = src->data[spixel++];
		  dest->data[dpixel++] = src->data[spixel++];
		}
	}
      y++;
    }
}

int		screen_define(char screen, void *mlx_ptr,
			      void *win_ptr, t_wolf *wolf)
{
  if (screen == 2)
    {
      mlx_put_image_to_window(mlx_ptr, win_ptr, wolf->tex[7].img_ptr, 0, 0);
      return (1);
    }
  else if (screen == 0)
    {
      mlx_put_image_to_window(mlx_ptr, win_ptr, wolf->tex[8].img_ptr, 0, 0);
      return (1);
    }
  return (0);
}

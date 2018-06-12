/*
** mini_map.c for minimap in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sun Dec  7 13:34:26 2014 Fisun Sergii
** Last update Sun Dec 21 19:00:24 2014 Fisun Sergii
*/

#include	<math.h>
#include	"mlx.h"
#include	"my_struct.h"

void		init_mmap(t_image *map)
{
  int		x;
  int		y;

  y = 0;
  while (y < 180)
    {
      x = 0;
      while (x < 180)
	{
	  my_put_pixel_image(map, x, y, 0xFFFFFFFF);
	  x++;
	}
      y++;
    }
}

void		make_cube(t_image *map, int x, int y, unsigned int color)
{
  int		x2;
  int		y1;
  int		x1;

  x1 = x;
  x2 = x + 20;
  y1 = y + 20;
  while (y < y1)
    {
      x1 = x;
      while (x1 < x2)
	{
	  my_put_pixel_image(map, x1, y, color);
	  x1++;
	}
      y++;
    }
}

void		get_pos_mmap(t_image *map, t_wolf *wolf)
{
  int		x1;
  int		y1;
  int		x2;
  int		y2;
  int		x;
  int		x3;
  int		y3;

  x1 = (int)wolf->pos->x - 5;
  y1 = (int)wolf->pos->y - 5;
  x2 = (int)wolf->pos->x + 4;
  y2 = (int)wolf->pos->y + 4;
  y3 = 0;
  while (++y1 <= y2)
    {
      x = x1;
      x3 = -1;
      while (++x <= x2 && ++x3 >= 0)
	if (x >= 0 && x < wolf->maps[wolf->c_map].height
	    && y1 >= 0 && y1 < wolf->maps[wolf->c_map].width &&
	    wolf->maps[wolf->c_map].map[x][y1] != 0)
	  make_cube(map, (x3 * 20), (y3 * 20), 0x0);
      y3++;
    }
}

void		make_mmap(t_image *map, t_wolf *wolf)
{
  init_mmap(map);
  get_pos_mmap(map, wolf);
  make_cube(map, 80, 80, 0xFF0000);
  mlx_put_image_to_window(wolf->win->mlx_ptr,
			  wolf->win->win_ptr, map->img_ptr, 0, MAP_POS);
}

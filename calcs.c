/*
** calcs.c for calcs in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sat Dec  6 16:37:07 2014 Fisun Sergii
** Last update Sun Dec 21 03:14:16 2014 Fisun Sergii
*/

#include	<math.h>
#include	"my_struct.h"

void		calc_X_Y(t_pos *pos, int x)
{
  float		a;

  a = RAD(pos->angle);
  pos->cosa = cos(a);
  pos->sina = sin(a);
  pos->y1 = (P * (float)(WIN_X / 2 - x) / WIN_X);
  pos->x1 = (pos->D * pos->cosa) - (pos->y1 * pos->sina);
  pos->y1 = (pos->D * pos->sina) + (pos->y1 * pos->cosa);
  pos->x1 = pos->x1 + pos->x;
  pos->y1 = pos->y1 + pos->y;
}

int		check_map_x(t_pos *pos, t_map *map, int x, int y)
{
  if (map->map[x][y] != 0)
    {
      pos->tx = x;
      pos->ty = y;
      return (1);
    }
  if (x > 0 && map->map[x - 1][y] != 0)
    {
      pos->tx = x - 1;
      pos->ty = y;
      return (1);
    }
  return (0);
}

float		calc_k_x(t_pos *pos, t_map *map)
{
  int		x;
  int		y;
  float		k;
  float		b;

  pos->side = 0;
  b = 200;
  x = 0;
  while (x < map->height)
    {
      k = calc_k(x , pos->x, pos->x1);
      y = calc_x(k, pos->y, pos->y1);
      if (k < b && k > 0 && y >= 0 &&
	  y < map->width && check_map_x(pos, map, x, y) == 1)
	b = k;
      x++;
    }
  return (calc_k_y(pos, b, map));
}

int		check_map_y(t_pos *pos, t_map *map, int x, int y)
{
  if (map->map[x][y] != 0)
    {
      pos->tx = x;
      pos->ty = y;
      pos->side = 1;
      return (1);
    }
  if (y > 0 && map->map[x][y - 1] != 0)
    {
      pos->tx = x;
      pos->ty = y - 1;
      pos->side = 1;
      return (1);
    }
  return (0);
}

float		calc_k_y(t_pos *pos, float b, t_map *map)
{
  int		x;
  int		y;
  float		k;

  y = 0;
  while (y < map->width)
    {
      k = calc_k(y, pos->y, pos->y1);
      x = calc_x(k, pos->x, pos->x1);
      if (k < b && k > 0 && x >= 0 &&
	  x < map->height && check_map_y(pos, map, x, y) == 1)
	b = k;
      y++;
    }
  return (b);
}

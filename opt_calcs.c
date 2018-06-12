/*
** opt_calc.c for opt_calc in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Thu Dec 11 02:03:29 2014 Fisun Sergii
** Last update Sat Dec 20 16:48:26 2014 Fisun Sergii
*/

#include	"my_struct.h"

float		calc_k(int x, float x0, float x1)
{
  int		pos_x0;
  int		pos_x1;
  float		k;

  x = x * 1000;
  pos_x0 = x0 * 1000;
  pos_x1 = x1 * 1000;
  k = (float)(x - pos_x0) / (float)(pos_x1 - pos_x0);
  return (k);
}

int		calc_x(float k, float y0, float y1)
{
  int		pos_y0;
  int		pos_y1;
  int		x;

  pos_y0 = y0 * 1000;
  pos_y1 = y1 * 1000;
  x = pos_y0 + (k * (pos_y1 - pos_y0));
  return (x / 1000);
}

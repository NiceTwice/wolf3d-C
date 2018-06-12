/*
** my_put_pixel_image.c for my_put_pixel_image in /home/fisun_s/rendu/MUL_2014_fdf
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Mon Nov 10 19:28:41 2014 Fisun Sergii
** Last update Sat Dec 20 13:38:51 2014 Fisun Sergii
*/

#include	"mlx.h"
#include	"my_struct.h"

int		my_put_pixel_image(t_image *img, int x,
				   int y, unsigned int color)
{
  int		pixel;

  pixel = (y * img->line_size) + (x * 4);
  if (x >= WIN_X || y >= WIN_Y || x <= 0 || y <= 0)
    return (0);
  img->data[pixel++] = color & 255;
  img->data[pixel++] = color >> 8 & 255;
  img->data[pixel] = color >> 16 & 255;
  return (0);
}

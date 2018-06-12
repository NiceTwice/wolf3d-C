/*
** my_drowline.c for my_drowline in /home/fisun_s/rendu/MUL_2014_fdf
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sun Nov  9 22:24:37 2014 Fisun Sergii
** Last update Sun Dec 21 21:38:41 2014 Fisun Sergii
*/

#include	"my_struct.h"

void		draw_sky(t_wolf *wolf, t_params wall)
{
  int		tx;
  int		y;
  int		ipixel;
  int		cpixel;

  tx = wolf->pos->ta_start + wall.x1;
  y = 0;
  while (y < wall.y1)
    {
      ipixel = (y * wolf->img->line_size) + (wall.x1 * 4);
      cpixel = (y * wolf->sky[(int)wolf->button->light].line_size) + (tx * 4);
      wolf->img->data[ipixel++] =
	wolf->sky[(int)wolf->button->light].data[cpixel++];
      wolf->img->data[ipixel++] =
	wolf->sky[(int)wolf->button->light].data[cpixel++];
      wolf->img->data[ipixel++] =
	wolf->sky[(int)wolf->button->light].data[cpixel++];
      y++;
    }
}

void	get_night(t_wolf *wolf, int ipixel, int tpixel, int texn)
{
  float	k;

  k = wolf->pos->k;
  if (wolf->button->cw == 2)
    k = k / 2;
  if (k < 1)
    k = 1;
  if (wolf->pos->side == 1)
    {
      wolf->img->data[ipixel++] = wolf->tex[texn].data[tpixel++] / 2 / k;
      wolf->img->data[ipixel++] = wolf->tex[texn].data[tpixel++] / 2 / k;
      wolf->img->data[ipixel] = wolf->tex[texn].data[tpixel] / 2 / k;
    }
  else
    {
      wolf->img->data[ipixel++] = wolf->tex[texn].data[tpixel++] / k;
      wolf->img->data[ipixel++] = wolf->tex[texn].data[tpixel++] / k;
      wolf->img->data[ipixel] = wolf->tex[texn].data[tpixel] / k;
    }
}

void	get_day(t_wolf *wolf, int ipixel, int tpixel, int texn)
{
  if (wolf->pos->side == 1)
    {
      wolf->img->data[ipixel++] = wolf->tex[texn].data[tpixel++] / 2;
      wolf->img->data[ipixel++] = wolf->tex[texn].data[tpixel++] / 2;
      wolf->img->data[ipixel] = wolf->tex[texn].data[tpixel] / 2;
    }
  else
    {
      wolf->img->data[ipixel++] = wolf->tex[texn].data[tpixel++];
      wolf->img->data[ipixel++] = wolf->tex[texn].data[tpixel++];
      wolf->img->data[ipixel] = wolf->tex[texn].data[tpixel];
    }

}

void	drow_line(t_wolf *wolf, t_params line, int texX, int texn)
{
  int	texY;
  int	tpixel;
  int	ipixel;
  int	h;

  h = wolf->h * 2;
  if (line.y1 < 0)
    line.y1 = 0;
  if (line.y2 > WIN_Y)
    line.y2 = WIN_Y;
  while (line.y1 <= line.y2)
    {
      texY = (line.y1 * 2 - WIN_Y + h) * (wolf->tex[texn].height / 2) / h;
      if (texY >= 0 && texY <= wolf->tex[texn].height &&
	  texX >= 0 && texX <= wolf->tex[texn].width)
	{
	  tpixel = (texY * wolf->tex[texn].line_size) + (texX * 4);
	  ipixel = (line.y1 * wolf->img->line_size) + (line.x1 * 4);
	  if (wolf->button->light == 1 && wolf->button->fire == 0)
	    get_night(wolf, ipixel, tpixel, texn);
	  else
	    get_day(wolf, ipixel, tpixel, texn);
	}
      line.y1++;
    }
}

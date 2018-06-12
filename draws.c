/*
** draws.c for draws in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Thu Dec 11 01:55:18 2014 Fisun Sergii
** Last update Sat Dec 12 10:42:29 2015 Fisun Sergii
*/

#include	"my_struct.h"

void		draw_wolf(t_wolf *wolf, int x, int texn, int texX)
{
  t_params	wall;

  wall.x1 = x;
  wall.y1 = wolf->hy - wolf->h;
  wall.y2 = wolf->hy + wolf->h;
  if (wolf->button->waza_mode == 0)
    draw_sky(wolf, wall);
  drow_line(wolf, wall, texX, texn);
  floor_casting(wolf, x, wall.y2);
}

void		floor_casting(t_wolf *wolf, int x, int y)
{
  float		weight;
  float		cx;
  float		cy;
  t_floor	floor;

  while (++y <= WIN_Y)
    {
      floor.dist = wolf->wy / (float)(2 * y - wolf->wy);
      weight = floor.dist / wolf->pos->k;
      cx = weight * wolf->pos->posx + (1 - weight) * wolf->pos->x;
      cy = weight * wolf->pos->posy + (1 - weight) * wolf->pos->y;
      floor.tx = (cx - (int)cx) * wolf->tex[wolf->floorn].width;
      floor.ty = (cy - (int)cy) * wolf->tex[wolf->floorn].height;
      if (floor.ty >= 0 && floor.ty <= wolf->tex[wolf->floorn].height &&
	  floor.tx >= 0 && floor.tx <= wolf->tex[wolf->floorn].width)
	{
	  draw_bot(wolf, floor, x, y);
	  if (wolf->button->waza_mode != 0)
	    {
	      floor.tx = (cx - (int)cx) * wolf->tex[wolf->button->t].width;
	      floor.ty = (cy - (int)cy) * wolf->tex[wolf->button->t].height;
	      draw_top(wolf, floor, x, (WIN_Y - y));
	    }
	}
    }
}

void		draw_top(t_wolf *wolf, t_floor floor, int x, int y)
{
  int		ipixel;
  int		tpixel;
  int		t;

  t = wolf->button->t;
  tpixel = (floor.ty * wolf->tex[t].line_size) + (floor.tx * 4);
  ipixel = (y * wolf->img->line_size) + (x * 4);
  if (wolf->button->cw == 2)
    floor.dist = floor.dist / 2;
  if (floor.dist < 1)
    floor.dist = 1;
  if (wolf->button->light == 1 && wolf->button->fire == 0)
    {
      wolf->img->data[ipixel++] = wolf->tex[t].data[tpixel++] / floor.dist;
      wolf->img->data[ipixel++] = wolf->tex[t].data[tpixel++] / floor.dist;
      wolf->img->data[ipixel++] = wolf->tex[t].data[tpixel++] / floor.dist;
    }
  else
    {
      wolf->img->data[ipixel++] = wolf->tex[t].data[tpixel++];
      wolf->img->data[ipixel++] = wolf->tex[t].data[tpixel++];
      wolf->img->data[ipixel++] = wolf->tex[t].data[tpixel++];
    }
}

void		draw_bot(t_wolf *wolf, t_floor floor, int x, int y)
{
  int		ipixel;
  int		tpixel;

  tpixel = (floor.ty * wolf->tex[wolf->floorn].line_size) + (floor.tx * 4);
  ipixel = (y * wolf->img->line_size) + (x * 4);
  if (wolf->button->cw == 2)
    floor.dist = floor.dist / 2;
  if (floor.dist < 1)
    floor.dist = 1;
  if (wolf->button->light == 1 && wolf->button->fire == 0)
    {
      wolf->img->data[ipixel++] =
	wolf->tex[wolf->floorn].data[tpixel++] / floor.dist;
      wolf->img->data[ipixel++] =
	wolf->tex[wolf->floorn].data[tpixel++] / floor.dist;
      wolf->img->data[ipixel++] =
	wolf->tex[wolf->floorn].data[tpixel++] / floor.dist;
    }
  else
    {
      wolf->img->data[ipixel++] = wolf->tex[wolf->floorn].data[tpixel++];
      wolf->img->data[ipixel++] = wolf->tex[wolf->floorn].data[tpixel++];
      wolf->img->data[ipixel++] = wolf->tex[wolf->floorn].data[tpixel++];
    }
}

int		get_texX(t_pos *pos, float k, int width)
{
  int		texX;
  int		x0;
  int		x1;
  int		y0;
  int		y1;

  x0 = pos->x * 1000;
  x1 = pos->x1 * 1000;
  y0 = pos->y * 1000;
  y1 = pos->y1 * 1000;
  pos->posy = ((y1 - y0) * k + y0) / 1000;
  pos->posx = ((x1 - x0) * k + x0) / 1000;
  if (pos->side == 0)
    texX = (1 - (pos->posy - (int)pos->posy)) * width;
  else
    texX = (pos->posx - (int)pos->posx) * width;
  return (texX);
}

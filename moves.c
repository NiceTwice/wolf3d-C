/*
** moves.c for moves in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sun Dec 14 06:24:19 2014 Fisun Sergii
** Last update Sat Dec 20 14:37:29 2014 Fisun Sergii
*/

#include	"my_struct.h"

void		move_forward(t_wolf *wolf)
{
  int		x;
  int		y;

  x = wolf->pos->x + (wolf->pos->cosa / 2);
  y = wolf->pos->y + (wolf->pos->sina / 2);
  if (x >= 0 && y >= 0 && x <= (wolf->maps[wolf->c_map].height - 1) &&
      y <= wolf->maps[wolf->c_map].width)
    {
      if (wolf->maps[wolf->c_map].map[x][y] == 0)
	{
	  wolf->pos->x = wolf->pos->x + (wolf->pos->cosa / wolf->speed);
	  wolf->pos->y = wolf->pos->y + (wolf->pos->sina / wolf->speed);
	}
      else if (wolf->maps[wolf->c_map].map[(int)wolf->pos->x][y] == 0)
	wolf->pos->y = wolf->pos->y + (wolf->pos->sina / wolf->speed);
      else if (wolf->maps[wolf->c_map].map[x][(int)wolf->pos->y] == 0)
	wolf->pos->x = wolf->pos->x + (wolf->pos->cosa / wolf->speed);
    }
}

void		move_back(t_wolf *wolf)
{
  int		x;
  int		y;

  x = wolf->pos->x - (wolf->pos->cosa / 2);
  y = wolf->pos->y - (wolf->pos->sina / 2);
  if (x >= 0 && y >= 0 && x <= (wolf->maps[wolf->c_map].height - 1) &&
      y <= wolf->maps[wolf->c_map].width)
    {
      if (wolf->maps[wolf->c_map].map[x][y] == 0)
	{
	  wolf->pos->x = wolf->pos->x - (wolf->pos->cosa / wolf->speed);
	  wolf->pos->y = wolf->pos->y - (wolf->pos->sina / wolf->speed);
	}
      else if (wolf->maps[wolf->c_map].map[(int)wolf->pos->x][y] == 0)
	wolf->pos->y = wolf->pos->y - (wolf->pos->sina / wolf->speed);
      else if (wolf->maps[wolf->c_map].map[x][(int)wolf->pos->y] == 0)
	wolf->pos->x = wolf->pos->x - (wolf->pos->cosa / wolf->speed);
    }
}

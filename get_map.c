/*
** get_map.c for get_map in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sat Dec  6 22:12:19 2014 Fisun Sergii
** Last update Sun Dec 21 23:34:56 2014 Fisun Sergii
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my_struct.h"

int		check_line(char *line)
{
  int		a;
  int		b;

  a = 0;
  b = 0;
  while (line[a] != 0)
    {
      if (b > 500)
	exit(write(1, "Error\n", 6));
      if (line[a] != ' ')
	{
	  while (line[a] != ' ' && line[a] != 0)
	    a++;
	  b++;
	}
      else
	a++;
    }
  return (b);
}

int		width_define(char *str, t_map *my_tab)
{
  char		*line;
  int		a;
  int		b;
  int		c;

  c = 0;
  a = 0;
  b = 0;
  while (a < (my_tab->height))
    {
      c = b;
      line = my_get_nextline(str, a);
      b = check_line(line);
      free(line);
      if (c != b && a != 0)
	exit(write(1, "Error\n", 6));
      a++;
    }
  return (b);
}

int		height_define(char *str)
{
  int		a;
  int		b;

  a = -1;
  b = 0;
  while (str[++a] != 0)
    {
      if (b > 500)
	exit(write(1, "Error\n", 6));
      if (str[a] == '\n')
	b++;
    }
  if (str[a - 1] != '\n')
    exit(write(1, "Error\n", 6));
  return (b);
}

char             **get_char_tab(char *str, t_map *map)
{
  char           **tab;
  int           a;

  a = -1;
  if ((tab = malloc(sizeof(char *) * map->height)) == NULL)
    exit(write(1, "Error\n", 6));
  while (++a < map->height)
    {
      if ((tab[a] = malloc(sizeof(char) * map->width)) == NULL)
        exit(write(1, "Error\n", 6));
    }
  tab = str_to_char_tab(tab, str, map);
  return (tab);
}

char             **str_to_char_tab(char **tab, char *str, t_map *map)
{
  char          *line;
  int           a;
  int           b;
  int           c;

  a = -1;
  while (++a < map->height)
    {
      c = -1;
      b = -1;
      line = my_get_nextline(str, a);
      while (++b < (map->width))
        {
          while (line[++c] == ' ');
          tab[a][b] = my_getnbr(&line[c]) % 8;
          while (line[++c] != ' ' && line[c] != 0);
        }
      free(line);
    }
  free(str);
  return (tab);
}

/*
** get_maps.c for get_maps in /home/fisun_s/wolftest
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sat Dec  6 23:01:26 2014 Fisun Sergii
** Last update Sun Dec 21 23:31:37 2014 Fisun Sergii
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	"my_struct.h"

char		*get_path(char *filename, char *dirname)
{
  int		a;
  int		b;
  char		*path;

  a = my_strlen(dirname);
  if (dirname[a - 1] != '/')
   a++;
  if ((path = malloc(sizeof(char) * (a + my_strlen(filename) + 1))) == NULL)
    exit(write(1, "Error\n", 6));
  path[a + my_strlen(filename)] = 0;
  a = -1;
  b = 0;
  while (dirname[++a] != 0)
    path[a] = dirname[a];
  if (dirname[a - 1] != '/')
    path[a++] = '/';
  while (filename[b] != 0)
    path[a++] = filename[b++];
  return (path);
}

void		get_maps(t_wolf *wolf)
{
  DIR		*dir;
  struct dirent	*my_dir;
  int		a;

  a = 0;
  wolf->maps_n = 0;
  if ((dir = opendir("maps")) == NULL)
    exit(write(1, "Error\n", 6));
  while ((my_dir = readdir(dir)) != NULL)
    if (my_dir->d_name[0] != '.')
      wolf->maps_n++;
  closedir(dir);
  if (wolf->maps_n == 0)
    exit(write(1, "Error\n", 6));
  if ((wolf->maps = malloc(sizeof(t_map) * wolf->maps_n)) == NULL)
    exit(write(1, "Error\n", 6));
  dir = opendir("maps");
  while ((my_dir = readdir(dir)) != NULL)
    if (my_dir->d_name[0] != '.')
      wolf->maps[a++] = get_map(my_dir->d_name,
				get_path(my_dir->d_name, "maps"));
  closedir(dir);
}

t_map		get_map(char *filename, char *path)
{
  t_map		map;
  char		*str;

  str = my_read_to_str(path);
  map.name = my_strdup(filename);
  map.height = height_define(str);
  map.width = width_define(str, &map);
  map.map = get_char_tab(str, &map);
  return (map);
}

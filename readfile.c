/*
** readfile.c for readfile in /home/fisun_s/rendu/minilibx
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sat Nov  8 22:15:58 2014 Fisun Sergii
** Last update Sun Dec 21 23:30:13 2014 Fisun Sergii
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	"my_struct.h"

char	*my_read(char *s1, char *s2)
{
  int	a;
  int	b;
  char	*str;

  a = my_strlen(s1) + my_strlen(s2);
  if ((str = malloc(sizeof(char) * (a + 1))) == NULL)
    exit(write(1, "Error\n", 6));
  str[a] = 0;
  a = -1;
  while (s1[++a] != 0)
    str[a] = s1[a];
  b = 0;
  while (s2[b] != 0)
    str[a++] = s2[b++];
  free(s1);
  return (str);
}

char	*my_read_to_str(char *file)
{
  char	*final_str;
  char  buffer[100001];
  int   len;
  int   fd;

  if ((final_str = malloc(sizeof(char) * 1)) == NULL)
    exit(write(1, "Error\n", 6));
  final_str[0] = 0;
  fd = open(file, O_RDONLY | O_DIRECTORY);
  if (fd > 0)
    exit(write(1, "Error\n", 6));
  fd = open(file, O_RDONLY);
  if (fd < 0)
    exit(write(1, "Error\n", 6));
  while ((len = read(fd, buffer, 100000)) > 0)
    {
      buffer[len] = 0;
      final_str = my_read(final_str, &buffer[0]);
    }
  close(fd);
  return (final_str);
}

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != 0)
    a++;
  return (a);
}

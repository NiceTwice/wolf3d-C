/*
** my_get_nextline.c for my_get_nextline in /home/fisun_s/rendu/minilibx
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Sat Nov  8 20:08:27 2014 Fisun Sergii
** Last update Sun Dec 21 23:32:25 2014 Fisun Sergii
*/

#include	<unistd.h>
#include	<stdlib.h>

char	*my_get_nextline(char *str, int a)
{
  int	b;
  int	c;
  char	*str1;

  b = -1;
  c = 0;
  while (str[++b] != 0 && c != a)
    {
      if (str[b] == '\n')
	c++;
    }
  c = 0;
  while (str[b + c] != 0 && str[b + c] != '\n')
    c++;
  if (str[b + c] != '\n')
    return (NULL);
  if ((str1 = malloc(sizeof(char) * (c + 1))) == NULL)
    exit(write(1, "Error\n", 6));
  str1[c] = 0;
  c = 0;
  while (str[b] != '\n' && str[b] != 0)
    str1[c++] = str[b++];
  return (str1);
}

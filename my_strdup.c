/*
** my_strdup.c for my_strdup in /home/fisun_s/rendu/Piscine_C_J08
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Wed Oct  8 10:21:19 2014 Fisun Sergii
** Last update Sun Dec 21 23:33:24 2014 Fisun Sergii
*/

#include	<unistd.h>
#include	<stdlib.h>

char	*my_strdup(char *src)
{
  int	a;
  int	b;
  char	*str;

  a = 0;
  b = 0;
  while (src[a] != 0)
    a++;
  if ((str = malloc(sizeof(char) * a + 1)) == NULL)
    exit(write(1, "Error\n", 6));
  while (b <= a)
    {
      str[b] = src[b];
      b++;
    }
  return (str);
}

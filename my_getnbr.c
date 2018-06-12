/*
** my_getnbr.c for my_getnbr in /home/fisun_s/rendu/Piscine_C_J04
** 
** Made by Fisun Sergii
** Login   <fisun_s@epitech.net>
** 
** Started on  Wed Oct 15 14:55:36 2014 Fisun Sergii
** Last update Wed Oct 15 16:29:15 2014 Fisun Sergii
*/

char	*mon_signe(char *str, int *minus)
{
  int	a;

  a = 0;
  *minus = 0;
  while (str[a] == '+' || str[a] == '-')
    {
      if (str[a] == '-')
	(*minus)++;
      a++;
    }
  return (&str[a]);
}

int	my_getnbr(char *str)
{
  int	a;
  int	minus;
  long	my_nb;
  int	nb;

  a = 0;
  my_nb = 0;
  str = mon_signe(str, &minus);
  while (str[a] >= '0' && str[a] <= '9')
    {
      my_nb = (my_nb * 10) + (str[a] - 48);
      a++;
    }
  if ((minus % 2) == 1)
    my_nb = my_nb * (-1);
  if (my_nb > 2147483647 || my_nb < -2147483648)
    return (0);
  nb = my_nb;
  return (nb);
}

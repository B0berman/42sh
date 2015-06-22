/*
** sm_getlong.c for strmut in /home/zack/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:31:21 2014 Antoine Favarel
** Last update sam. mai 23 18:06:57 2015 Antoine Favarel
*/

#include	"neptune/strmut.h"

long		sm_getlong(char *str)
{
  unsigned long	nb;
  int		signe;
  size_t	ite;

  nb = 0;
  signe = 1;
  if (!str)
    return (nb);
  if (str[0] == '-')
    signe = -1;
  ite = (signe == -1) ? 1 : 0;
  while (str[ite])
    {
      if ((nb = nb * 10 + str[ite] - '0') > LONG_MAX)
	return (((long)nb*signe));
      ite++;
    }
  return (((long)nb*signe));
}

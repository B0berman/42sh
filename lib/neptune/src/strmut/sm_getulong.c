/*
** sm_getulong.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:34:08 2014 Antoine Favarel
** Last update jeu. avril 23 17:03:12 2015 Antoine Favarel
*/

#include	"strmut.h"

unsigned long	sm_getulong(char *str)
{
  unsigned long	nb;
  size_t	ite;

  nb = 0;
  ite = 0;
  if (!str)
    return (nb);
  while (str[ite])
    {
      nb = nb * 10 + str[ite] - '0';
      ite++;
    }
  return (nb);
}

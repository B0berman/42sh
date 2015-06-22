/*
** sm_getuint.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:27:08 2014 Antoine Favarel
** Last update jeu. avril 23 17:03:09 2015 Antoine Favarel
*/

#include	"strmut.h"

unsigned int	sm_getuint(char *str)
{
  long		nb;
  size_t	ite;

  nb = 0;
  ite = 0;
  if (!str)
    return (nb);
  while (str[ite])
    {
      if ((nb = nb * 10 + str[ite] - '0') > UINT_MAX)
	return (((unsigned int)nb));
      ite++;
    }
  return (((unsigned int)nb));
}

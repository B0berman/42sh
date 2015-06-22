/*
** sm_cmp.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:18:45 2014 Antoine Favarel
** Last update jeu. avril 23 17:02:31 2015 Antoine Favarel
*/

#include	"strmut.h"

int		sm_cmp(char *s1, char *s2)
{
  size_t	ite;

  ite = 0;
  if (!s1 || !s2)
    return (-2);
  while (s1[ite])
    {
      if (s1[ite] != s2[ite])
	return ((s1[ite] < s2[ite]) ? -1 : 1);
      ite++;
    }
  if (s1[ite] != s2[ite])
    return ((s1[ite] < s2[ite]) ? -1 : 1);
  return (0);
}

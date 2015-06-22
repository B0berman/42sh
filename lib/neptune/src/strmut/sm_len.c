/*
** sm_len.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:37:19 2014 Antoine Favarel
** Last update jeu. avril 23 17:03:19 2015 Antoine Favarel
*/

#include	"strmut.h"

size_t		sm_len(char *str)
{
  size_t	ite;

  ite = 0;
  if (!str)
    return (0);
  while (str[ite])
    ite++;
  return (ite);
}

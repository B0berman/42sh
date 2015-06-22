/*
** sm_egal.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:16:21 2014 Antoine Favarel
** Last update jeu. avril 23 17:02:47 2015 Antoine Favarel
*/

#include	"strmut.h"

int		sm_egal(char *s1, char *s2)
{
  return ((sm_cmp(s1, s2) == 0) ? 1 : 0);
}

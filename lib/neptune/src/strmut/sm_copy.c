/*
** sm_copy.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. févr. 24 17:49:17 2015 Antoine Favarel
** Last update jeu. avril 23 17:02:34 2015 Antoine Favarel
*/

#include	"strmut.h"

void		sm_copy(char *dest, char *src)
{
  size_t	i;

  i = 0;
  while (src[i])
  {
    dest[i] = src[i];
    i++;
  }
}

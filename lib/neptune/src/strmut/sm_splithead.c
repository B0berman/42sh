/*
** sm_splithead.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. févr. 24 17:58:59 2015 Antoine Favarel
** Last update jeu. avril 23 16:51:46 2015 Antoine Favarel
*/

#include	"strmut.h"

char		*sm_splithead(char *str, char spliter)
{
  size_t	i;

  i = 0;
  while (str[i])
  {
    if (str[i] == spliter)
      return (sm_dupn(str, i));
    i++;
  }
  return (sm_dup(str));
}

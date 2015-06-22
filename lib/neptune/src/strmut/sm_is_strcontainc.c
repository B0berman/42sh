/*
** sm_is_strcontainc.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. févr. 24 11:18:07 2015 Antoine Favarel
** Last update jeu. avril 23 17:03:16 2015 Antoine Favarel
*/

#include	"strmut.h"

int		sm_is_strcontainc(char *str, char c)
{
  int		i;

  if (!str)
    return (-1);
  i = -1;
  while (str[++i])
    if (str[i] == c)
      return (1);
  return (0);
}

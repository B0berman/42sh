/*
** sm_dupn.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. févr. 24 11:05:30 2015 Antoine Favarel
** Last update jeu. avril 23 17:02:45 2015 Antoine Favarel
*/

#include	"strmut.h"

char		*sm_dupn(char *str, size_t len)
{
  int		i;
  char		*n_str;

  if (!str)
    return (NULL);
  if (!(n_str = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  i = -1;
  while (str[++i] && i < ((int)len))
    n_str[i] = str[i];
  n_str[i] = '\0';
  return (n_str);
}

/*
** sm_splittail.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. févr. 24 18:05:20 2015 Antoine Favarel
** Last update jeu. avril 23 16:57:13 2015 Antoine Favarel
*/

#include	"strmut.h"

char		*sm_splittail(char *str, char spliter)
{
  size_t	i;

  i = 0;
  while (str[i] && str[i] != spliter)
    i++;
  if (!str[i])
    return (NULL);
  return (sm_dup(&str[i + 1]));
}

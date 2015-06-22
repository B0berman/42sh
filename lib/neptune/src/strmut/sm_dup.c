/*
** sm_dup.c for strmut in /home/zack/Epitech/42sh/lib/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:12:49 2014 Antoine Favarel
** Last update dim. mai 24 22:21:00 2015 Antoine Favarel
*/

#include	"strmut.h"

char		*sm_dup(char *str)
{
  char		*n_str;
  size_t	ite;
  size_t	size;

  size = sm_len(str);
  if (!str || !(n_str = malloc(sizeof(char) * (size + 1))))
    return (NULL);
  ite = 0;
  while (ite < size)
    {
      n_str[ite] = str[ite];
      ite++;
    }
  n_str[ite] = '\0';
  return (n_str);
}

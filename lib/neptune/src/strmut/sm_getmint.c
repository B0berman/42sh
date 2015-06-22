/*
** sm_getmint.c for strmut in /home/zack/Epitech/42sh/lib/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 15:40:50 2014 Antoine Favarel
** Last update dim. mai 24 22:20:16 2015 Antoine Favarel
*/

#include	"strmut.h"

int		*sm_getmint(char *str)
{
  int		*value;

  if (!str)
    return (NULL);
  if (!(value = malloc(sizeof(int))))
    return (NULL);
  (*value) = sm_getint(str);
  return (value);
}

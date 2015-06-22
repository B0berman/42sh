/*
** sm_getmulong.c for strmut in /home/zack/Epitech/42sh/lib/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 15:46:11 2014 Antoine Favarel
** Last update dim. mai 24 22:21:15 2015 Antoine Favarel
*/

#include	"strmut.h"

unsigned long	*sm_getmulong(char *str)
{
  unsigned long	*value;

  if (!str)
    return (NULL);
  if (!(value = malloc(sizeof(unsigned long))))
    return (NULL);
  (*value) = sm_getulong(str);
  return (value);
}

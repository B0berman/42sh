/*
** sm_getmlong.c for strmut in /home/zack/Epitech/42sh/lib/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 15:44:59 2014 Antoine Favarel
** Last update dim. mai 24 22:20:30 2015 Antoine Favarel
*/

#include	"strmut.h"

long		*sm_getmlong(char *str)
{
  long		*value;

  if (!str)
    return (NULL);
  if (!(value = malloc(sizeof(long))))
    return (NULL);
  (*value) = sm_getlong(str);
  return (value);
}

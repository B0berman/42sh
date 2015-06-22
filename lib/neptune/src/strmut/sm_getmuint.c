/*
** sm_getmuint.c for strmut in /home/zack/Epitech/42sh/lib/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 15:43:16 2014 Antoine Favarel
** Last update dim. mai 24 22:20:44 2015 Antoine Favarel
*/

#include	"strmut.h"

unsigned int	*sm_getmuint(char *str)
{
  unsigned int	*value;

  if (!str)
    return (NULL);
  if (!(value = malloc(sizeof(unsigned int))))
    return (NULL);
  (*value) = sm_getuint(str);
  return (value);
}

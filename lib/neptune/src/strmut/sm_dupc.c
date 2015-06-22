/*
** sm_dupc.c for strmut in /home/zack/Epitech/42sh/lib/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:11:47 2014 Antoine Favarel
** Last update dim. mai 24 22:19:36 2015 Antoine Favarel
*/

#include	"strmut.h"

char		*sm_dupc(char c)
{
  char		*s;

  if (!(s = malloc(sizeof(char) * 2)))
    return (NULL);
  s[0] = c;
  s[1] = '\0';
  return (s);
}

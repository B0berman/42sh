/*
** c_dredl.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. mai 22 14:14:13 2015 Antoine Favarel
** Last update ven. mai 22 14:16:25 2015 Antoine Favarel
*/

#include	"coquillage.h"
#include	"neptune/strmut.h"

int		c_dredl(t_system *sys, t_execute *e)
{
  char		*str;

  while ((str = sys->in->nextline(sys->in, '\n'))
      && !sm_egal(str, e->red_value));
  return (c_exec(sys, e));
}

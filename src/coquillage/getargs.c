/*
** getargs.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by wachow_a
** Login   <wachow_a@epitech.net>
** 
** Started on  jeu. mai 21 21:53:21 2015 wachow_a
** Last update dim. mai 24 22:02:28 2015 Antoine Favarel
*/

#include	<stdlib.h>

#include	"coquillage.h"
#include	"neptune/strmut.h"

char		**getargs(t_execute *e)
{
  char		**args;
  t_elem	*tmp;
  int		i;

  i = 1;
  if (!(args = malloc(sizeof(char*) * (e->params->length + 2))))
    return (NULL);
  args[0] = sm_dup(e->label);
  e->params->rewind(e->params);
  while ((tmp = e->params->next(e->params)))
    args[i++] = sm_dup((char*)tmp->mem);
  args[i] = NULL;
  return (args);
}

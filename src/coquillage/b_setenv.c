/*
** b_setenv.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Pierre de Berny
** Login   <Moon@epitech.net>
** 
** Started on  Wed May 20 15:10:59 2015 Pierre de Berny
** Last update dim. mai 24 15:51:49 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"coquillage.h"

static int	setenv_error(t_system *sys)
{
  sys->out->fd = 2;
  sys->print(sys, "setenv: Too many arguments.\n");
  sys->out->fd = 1;
  return (1);
}

static int	setenv_success(t_system *sys, t_execute *setenv)
{
  t_elem	*tmp;

  tmp = setenv->params->first;
  if (setenv->params->length == 0)
    b_env(sys, setenv);
  else if (setenv->params->length == 1)
    sys->setenv(sys, (char*)tmp->mem, "");
  else if (setenv->params->length == 2)
    sys->setenv(sys, (char*)tmp->mem, (char*)tmp->next->mem);
  return (0);

}

int		b_setenv(t_system *sys, t_execute *setenv)
{
  if (setenv->params->length > 2)
    return (setenv_error(sys));
  else
    return (setenv_success(sys, setenv));
}

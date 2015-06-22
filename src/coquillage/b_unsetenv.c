/*
** b_unsetenv.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Pierre de Berny
** Login   <Moon@epitech.net>
** 
** Started on  Thu May 21 11:36:25 2015 Pierre de Berny
** Last update jeu. mai 21 22:14:01 2015 Antoine Favarel
*/

#include	"coquillage.h"

static int	unsetenv_error(t_system *sys)
{
  sys->print(sys, "unsetenv: Too few arguments.\n");
  return (1);
}

static int	unsetenv_success(t_system *sys, t_execute *unsetenv)
{
  t_elem	*tmp;

  unsetenv->params->rewind(unsetenv->params);
  while ((tmp = unsetenv->params->next(unsetenv->params)))
    sys->unsetenv(sys, (char*)tmp->mem);
  return (0);
}

int		b_unsetenv(t_system *sys, t_execute *unsetenv)
{
  if (unsetenv->params->length > 0)
    return (unsetenv_success(sys, unsetenv));
  else
    return (unsetenv_error(sys));
}

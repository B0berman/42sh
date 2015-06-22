/*
** system_isenable.c for system in /home/zack/neptune/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 19:29:02 2015 Antoine Favarel
** Last update dim. mai 24 02:17:47 2015 Antoine Favarel
*/

#include	"neptune/system.h"
#include	"neptune/strmut.h"

int		system_isenable(t_system *this, char *option)
{
  t_elem	*elem;
  t_opt		*opt;

  if (!this)
    return (-1);
  this->opts->rewind(this->opts);
  while ((elem = this->opts->next(this->opts)))
    if (sm_egal((opt = (t_opt*)elem->mem)->option, option))
      return (opt->is_enable);
  return (0);
}

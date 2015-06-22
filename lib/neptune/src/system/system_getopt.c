/*
** system_getopt.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 20:16:47 2015 Antoine Favarel
** Last update dim. avril 26 20:19:16 2015 Antoine Favarel
*/

#include	"neptune/system.h"
#include	"neptune/strmut.h"

char		*system_getopt(t_system *this, char *option)
{
  t_elem	*elem;
  t_opt		*opt;

  if (!this || !option)
    return (NULL);
  this->opts->rewind(this->opts);
  while ((elem = this->opts->next(this->opts)))
    if (sm_egal((opt = (t_opt*)elem->mem)->option, option))
      return (opt->value);
  return (NULL);
}

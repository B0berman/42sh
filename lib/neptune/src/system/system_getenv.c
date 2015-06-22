/*
** system_getenv.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 20:52:32 2015 Antoine Favarel
** Last update dim. avril 26 21:09:57 2015 Antoine Favarel
*/

#include	"neptune/system.h"
#include	"neptune/strmut.h"

char		*system_getenv(t_system *this, char *key)
{
  t_elem	*elem;
  t_enventry	*entry;

  if (!this || !key)
    return (NULL);
  this->env_list->rewind(this->env_list);
  while ((elem = this->env_list->next(this->env_list)))
    if (sm_egal((entry = (t_enventry*)elem->mem)->key, key))
      return (entry->value);
  return (NULL);
}

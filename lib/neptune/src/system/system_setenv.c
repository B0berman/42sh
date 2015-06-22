/*
** system_setenv.c for system in /home/zack/neptune/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 20:19:39 2015 Antoine Favarel
** Last update ven. mai 22 17:09:59 2015 Antoine Favarel
*/

#include	"neptune/system.h"
#include	"neptune/strmut.h"

void		system_setenv(t_system *this, char *key, char *value)
{
  t_elem	*elem;
  t_enventry	*entry;

  if (!this || !key || !value)
    return ;
  this->env_list->rewind(this->env_list);
  while ((elem = this->env_list->next(this->env_list)))
    if (sm_egal((entry = (t_enventry*)elem->mem)->key, key))
    {
      entry->value = value;
      return ;
    }
  this->env_list->push(this->env_list,
      _wrap(new_enventry(key, value), sizeof(t_enventry)));
}

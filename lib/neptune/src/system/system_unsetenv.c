/*
** system_unsetenv.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 21:10:11 2015 Antoine Favarel
** Last update dim. avril 26 21:13:25 2015 Antoine Favarel
*/

#include	"neptune/system.h"
#include	"neptune/strmut.h"

void		system_unsetenv(t_system *this, char *key)
{
  t_elem	*elem;
  t_enventry	*entry;

  if (!this || !key)
    return ;
  this->env_list->rewind(this->env_list);
  while ((elem = this->env_list->next(this->env_list)))
    if (sm_egal((entry = (t_enventry*)elem->mem)->key, key))
    {
      this->env_list->remove(this->env_list, elem);
      return ;
    }
}

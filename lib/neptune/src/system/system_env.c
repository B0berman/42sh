/*
** system_env.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 21:13:39 2015 Antoine Favarel
** Last update dim. avril 26 22:46:34 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/system.h"
#include	"neptune/strmut.h"

char		**system_env(t_system *this)
{
  char		**env;
  t_enventry	*entry;
  int		i;

  if (!this || this->env_list->length == 0)
    return (NULL);
  i = -1;
  if (!(env = malloc(sizeof(char*) * this->env_list->length + 1)))
    return (NULL);
  while (++i < (int) this->env_list->length)
  {
    entry = (t_enventry*)this->env_list->at(this->env_list, i)->mem;
    env[i] = sm_cat(entry->key, "=");
    env[i] = sm_cat(env[i], entry->value);
  }
  env[i] = NULL;
  return (env);
}

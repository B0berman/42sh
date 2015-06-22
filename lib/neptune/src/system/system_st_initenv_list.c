/*
** system_st_initenv_list.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:43:02 2015 Antoine Favarel
** Last update dim. avril 26 18:47:36 2015 Antoine Favarel
*/

#include	"neptune/system.h"
#include	"neptune/strmut.h"

t_list		*system_st_initenv_list(char **env)
{
  int		i;
  t_list	*env_list;
  char		*key;
  char		*value;

  i = -1;
  env_list = new_list();
  if (!env)
    return (env_list);
  while (env[++i] != NULL)
  {
    key = sm_splithead(env[i], '=');
    value = sm_splittail(env[i], '=');
    env_list->push(env_list,
	_wrap(new_enventry(key, value), sizeof(t_enventry)));
  }
  return (env_list);
}

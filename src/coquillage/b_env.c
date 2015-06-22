/*
** b_env.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Pierre de Berny
** Login   <Moon@epitech.net>
** 
** Started on  Thu May 21 11:17:46 2015 Pierre de Berny
** Last update ven. mai 22 17:02:04 2015 Antoine Favarel
*/

#include	"coquillage.h"

int		b_env(t_system *sys, t_execute *env)
{
  t_elem	*tmp;

  tmp = sys->env_list->first;
  while (tmp)
    {
      sys->print(sys, "%s=%s\n",
	  ((t_enventry*)tmp->mem)->key,
	  ((t_enventry*)tmp->mem)->value);
      tmp = tmp->next;
    }
  return (0);
}

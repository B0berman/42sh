/*
** new_system.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:11:18 2015 Antoine Favarel
** Last update dim. avril 26 18:26:30 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/system.h"

t_system	*new_system(int argc, char **argv, char **env)
{
  t_system	*system;

  if (!(system = malloc(sizeof(t_system))))
    return (NULL);
  init_system(system, argc, argv, env);
  return (system);
}

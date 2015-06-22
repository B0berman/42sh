/*
** uninit_system.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:35:08 2015 Antoine Favarel
** Last update dim. avril 26 18:36:46 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/system.h"

void		uninit_system(t_system *system)
{
  if (system)
  {
    delete_list(system->args);
    delete_list(system->env_list);
    delete_list(system->opts);
    free(system->in);
    free(system->out);
    free(system->err);
  }
}

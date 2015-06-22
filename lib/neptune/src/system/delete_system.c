/*
** delete_system.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:36:54 2015 Antoine Favarel
** Last update dim. avril 26 18:37:47 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/system.h"

void		delete_system(t_system *system)
{
  uninit_system(system);
  if (system)
    free(system);
}

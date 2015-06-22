/*
** delete_manager.c for manager in /home/zack/Projects/neptune_architecte/src/clust/manager
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. avril 23 16:09:05 2015 Antoine Favarel
** Last update lun. avril 27 16:07:05 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"clust/manager.h"

void		delete_manager(t_manager *manager)
{
  uninit_manager(manager);
  if (manager)
    free(manager);
}

/*
** new_manager.c for manager in /home/zack/Projects/neptune_architecte/src/clust/manager
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 10:40:36 2015 Antoine Favarel
** Last update mar. avril 21 10:42:05 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"clust/manager.h"

t_manager	*new_manager(char *src, int port, int coexiam)
{
  t_manager	*manager;

  if (!(manager = malloc(sizeof(t_manager))))
    return (NULL);
  init_manager(manager, src, port, coexiam);
  return (manager);
}

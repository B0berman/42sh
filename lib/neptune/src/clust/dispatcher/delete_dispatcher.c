/*
** delete_dispatcher.c for dispatcher in /home/zack/Projects/neptune_architecte/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 15:46:48 2015 Antoine Favarel
** Last update mar. avril 21 15:47:56 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"clust/dispatcher.h"

void		delete_dispatcher(t_dispatcher *dispatcher)
{
  uninit_dispatcher(dispatcher);
  if (dispatcher)
    free(dispatcher);
}

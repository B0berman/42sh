/*
** uninit_dispatcher.c for dispatcher in /home/zack/Projects/neptune_architecte/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 15:48:32 2015 Antoine Favarel
** Last update ven. avril 24 19:10:27 2015 Antoine Favarel
*/

#include	"clust/dispatcher.h"

void		uninit_dispatcher(t_dispatcher *dispatcher)
{
  if (dispatcher)
  {
    uninit_server((t_server *)dispatcher);
    delete_list(dispatcher->data);
    delete_list(dispatcher->orders);
    delete_list(dispatcher->responds);
  }
}

/*
** init_dispatcher.c for dispatcher in /home/zack/Projects/neptune_architecte/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 14:33:16 2015 Antoine Favarel
** Last update sam. avril 25 00:29:52 2015 Antoine Favarel
*/

#include	"clust/dispatcher.h"

static void	init_dispatcher_methods(t_dispatcher *dispatcher)
{
  dispatcher->update = &(dispatcher_update);
  dispatcher->open = &(dispatcher_open);
}

static void	init_dispatcher_values(t_dispatcher *dispatcher)
{
  dispatcher->data = new_list();
  dispatcher->orders = new_list();
  dispatcher->responds = new_list();
  dispatcher->gst_connection = &(dispatcher_connection);
}

void		init_dispatcher(t_dispatcher *d, char *ad, int port)
{
  if (d)
  {
    init_server((t_server*)d, ad, port);
    init_dispatcher_methods(d);
    init_dispatcher_values(d);
  }
}

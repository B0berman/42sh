/*
** dispatcher_update.c for dispatcher in /home/zack/Projects/neptune_architecte/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 15:37:50 2015 Antoine Favarel
** Last update lun. avril 27 16:09:01 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"clust/dispatcher.h"

static void	send_data(t_dispatcher *this, t_socket *client)
{
  t_metadata	*meta;
  t_elem	*data;

  meta = new_metadata(MR_DATA, MD_LIST);
  data = _wrap(meta, sizeof(t_metadata));
  data->save(data, (t_io*)client);
  this->data->save(this->data, (t_io*)this);
  free(meta);
  delete_elem(data);
}

void		dispatcher_update(t_dispatcher *this)
{
  t_elem	*elem;
  t_socket	*client;

  this->clients->lock(this->clients);
  this->clients->rewind(this->clients);
  while ((elem = this->clients->next(this->clients)))
    if ((client = (t_socket*)elem->mem))
      send_data(this, client);
  this->clients->unlock(this->clients);
}

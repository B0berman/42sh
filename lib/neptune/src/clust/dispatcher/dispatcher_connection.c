/*
** dispatcher_connection.c for dispatcher in /home/zack/Projects/neptune_architecte/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 14:58:12 2015 Antoine Favarel
** Last update mer. avril 29 14:51:42 2015 Antoine Favarel
*/

#include	<signal.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"neptune/clust/dispatcher.h"

static void	send_data(t_dispatcher *this, t_socket *client)
{
  t_metadata	*meta;
  t_elem	*data;

  meta = new_metadata(MR_DATA, MD_LIST);
  data = _wrap(meta, sizeof(t_metadata));
  client->lock(client);
  data->save(data, (t_io*)client);
  this->data->save(this->data, (t_io*)client);
  client->unlock(client);
  free(meta);
  delete_elem(data);
}

static void	send_order(t_socket *s, t_elem *e, t_list *lo)
{
  t_metadata	*meta;
  t_elem	*data;
  int		id;

  while (lo->get(lo, (id = rand())));
  e->id = id;
  meta = new_metadata(MR_ORDER, MD_DATA);
  data = _wrap(meta, sizeof(t_metadata));
  s->lock(s);
  data->save(data, (t_io*)s);
  lo->push(lo, e);
  e->save(e, (t_io*)s);
  s->unlock(s);
  free(meta);
  delete_elem(data);
}

static void	*thread_poporder(void *arg)
{
  t_d_arg	*a;
  t_dispatcher	*this;
  t_socket	*client;
  t_elem	*elem;
  t_list	*l_orders;

  a = (t_d_arg*)arg;
  this = a->server;
  client = a->socket;
  l_orders = a->l_orders;
  client->is_assync = 1;
  while (client->is_assync)
    while ((elem = this->orders->popret(this->orders)))
      if (client->is_assync)
	send_order(client, elem, l_orders);
      else
      {
	this->orders->push(this->orders, elem);
	return (NULL);
      }
  return (NULL);
}

static void	st_network(t_dispatcher *this, t_socket *client, t_list *lo)
{
  t_elem	*respond;
  t_elem	*akn;
  t_metadata	*meta;

  respond = new_elem();
  akn = _wrap(new_metadata(MR_AKN, MD_DATA), sizeof(t_metadata));
  while (respond->load(respond, (t_io*)client) == EXIT_SUCCESS)
  {
    client->lock(client);
    if ((meta = (t_metadata*)respond->mem)->role == MR_RESPONS)
    {
      if (respond->load(respond, (t_io*)client) == EXIT_SUCCESS)
	this->responds->push(this->responds, respond->dup(respond));
      else
	this->orders->push(this->orders, lo->get(lo, respond->id));
      akn->save(akn, (t_io*)client);
    }
    lo->remove(lo, lo->get(lo, respond->id));
    client->unlock(client);
  }
}

void		*dispatcher_connection(void *arg)
{
  t_s_arg	*a;
  t_d_arg	*da;
  t_dispatcher	*this;
  t_socket	*client;
  t_list	*l_orders;
  pthread_t	th;

  if (!(da = malloc(sizeof(t_d_arg))))
    return (NULL);
  l_orders = new_list();
  a = (t_s_arg*)arg;
  this = a->server;
  client = a->socket;
  da->server = this;
  da->socket = client;
  da->l_orders = l_orders;
  send_data(this, client);
  pthread_create(&th, NULL, &(thread_poporder), da);
  st_network(this, client, l_orders);
  client->is_assync = 0;
  pthread_cond_broadcast(&this->orders->is_fill);
  pthread_join(th, NULL);
  this->orders->put(this->orders, l_orders);
  return (NULL);
}

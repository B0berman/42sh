/*
** server_main.c for server in /home/zack/Projects/neptune_architecte/src/server
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 13:48:15 2015 Antoine Favarel
** Last update mer. avril 29 16:52:59 2015 Antoine Favarel
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<netinet/tcp.h>
#include		<arpa/inet.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		"neptune/server.h"

static t_s_arg		*st_arg(t_server *server, t_socket *socket)
{
  t_s_arg		*arg;

  if (!(arg = malloc(sizeof(t_s_arg))))
    return (NULL);
  arg->server = (void*)server;
  arg->socket = (void*)socket;
  return (arg);
}

void			*server_main(void *wrapper)
{
  t_server		*this;
  t_socket		*socket;
  struct sockaddr_in	sin;
  int			fd;
  socklen_t		size;
  t_s_arg		*arg;
  int			true;

  true = 1;
  if (!(this = (t_server*)wrapper))
    return (NULL);
  size = sizeof(struct sockaddr_in);
  while (this->is_assync)
    if ((fd = accept(this->fd, (struct sockaddr*)&sin, &size)) >= 0)
    {
      socket = new_socket("/client", sin.sin_port);
      socket->fd = fd;
      setsockopt(socket->fd, IPPROTO_TCP, TCP_NODELAY, &true, sizeof(int));
      arg = st_arg(this, socket);
      this->clients->push(this->clients, _wrap(socket, sizeof(t_socket)));
      pthread_create(&socket->main, NULL, this->gst_connection, arg);
    }
  return (NULL);
}

/*
** dispatcher_open.c for dispatcher in /home/zack/Projects/neptune_architecte/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 14:40:30 2015 Antoine Favarel
** Last update mer. avril 29 16:49:27 2015 Antoine Favarel
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<netinet/tcp.h>
#include		<arpa/inet.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		"neptune/clust/dispatcher.h"

int			dispatcher_open(t_dispatcher *this)
{
  struct sockaddr_in	sin;
  int			true;

  true = 1;
  if (!this)
    return (EXIT_FAILURE);
  srand(time(NULL));
  if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (EXIT_FAILURE);
  setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int));
  setsockopt(this->fd, IPPROTO_TCP, TCP_NODELAY, &true, sizeof(int));
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(this->port);
  if (bind(this->fd, (struct sockaddr *)&sin, sizeof(struct sockaddr)) == -1)
    return (EXIT_FAILURE);
  if (listen(this->fd, 25) == -1)
    return (EXIT_FAILURE);
  if (pthread_create(&this->main, NULL, &(server_main), this) != 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

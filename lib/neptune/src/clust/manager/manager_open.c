/*
** manager_open.c for manager in /home/zack/Projects/neptune_architecte/src/clust/manager
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 10:48:55 2015 Antoine Favarel
** Last update mer. avril 29 16:53:30 2015 Antoine Favarel
*/

#include		<stdio.h>
#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<netinet/tcp.h>
#include		<arpa/inet.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		"neptune/clust/manager.h"

int			manager_open(t_manager *this)
{
  struct hostent	*hostinfo;
  struct sockaddr_in	sin;
  int			true;

  true = 1;
  if (!this)
    return (EXIT_FAILURE);
  if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (EXIT_FAILURE);
  if (!(hostinfo = gethostbyname(this->src)))
    return (EXIT_FAILURE);
  setsockopt(this->fd, IPPROTO_TCP, TCP_NODELAY, &true, sizeof(int));
  sin.sin_addr = *(struct in_addr*)hostinfo->h_addr;
  sin.sin_port = htons(this->port);
  sin.sin_family = AF_INET;
  if (connect(this->fd, (struct sockaddr *)&sin,
	sizeof(struct sockaddr)) != 0)
    return (EXIT_FAILURE);
  if (pthread_create(&this->main, NULL, &(manager_main), this) != 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

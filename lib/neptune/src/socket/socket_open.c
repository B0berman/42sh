/*
** socket_open.c for socket in /home/zack/Projects/neptune_architecte/src/socket
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 21:23:36 2015 Antoine Favarel
** Last update lun. avril 20 14:09:10 2015 Antoine Favarel
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		"socket.h"

int			socket_open(t_socket *this)
{
  struct hostent	*hostinfo;
  struct sockaddr_in	sin;

  if (!this)
    return (EXIT_FAILURE);
  if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (EXIT_FAILURE);
  if (!(hostinfo = gethostbyname(this->src)))
    return (EXIT_FAILURE);
  sin.sin_addr = *(struct in_addr*)hostinfo->h_addr;
  sin.sin_port = htons(this->port);
  sin.sin_family = AF_INET;
  if (connect(this->fd, (struct sockaddr *)&sin,
	sizeof(struct sockaddr)) == -1)
    return (EXIT_FAILURE);
  if (this->is_assync)
    if (pthread_create(&this->main, NULL, &(socket_main), this) != 0)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

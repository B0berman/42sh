/*
** server_open.c for server in /home/zack/Projects/neptune_architecte/src/server
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 13:32:22 2015 Antoine Favarel
** Last update lun. avril 27 16:02:48 2015 Antoine Favarel
*/

#include		<sys/types.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		<arpa/inet.h>
#include		<netdb.h>
#include		<stdlib.h>
#include		"neptune/server.h"

int			server_open(t_server *this)
{
  struct sockaddr_in	sin;
  int			true;

  true = 1;
  if (!this)
    return (EXIT_FAILURE);
  if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (EXIT_FAILURE);
  setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &true, sizeof(int));
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(this->port);
  if (bind(this->fd, (struct sockaddr *)&sin, sizeof(struct sockaddr)) == -1)
    return (EXIT_FAILURE);
  if (listen(this->fd, 25) == -1)
    return (EXIT_FAILURE);
  if (this->is_assync)
    if (pthread_create(&this->main, NULL, &(server_main), this) != 0)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

/*
** init_socket.c for socket in /home/zack/Projects/neptune_architecte/src/socket
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 21:14:23 2015 Antoine Favarel
** Last update dim. avril 19 21:55:32 2015 Antoine Favarel
*/

#include	"socket.h"

static void	init_socket_methods(t_socket *socket)
{
  socket->open = &(socket_open);
}

static void	init_socket_values(t_socket *socket, int port)
{
  socket->port = port;
  socket->is_assync = 0;
}

void		init_socket(t_socket *socket, char *addr, int port)
{
  if (socket)
  {
    init_io((void*)socket, addr);
    init_socket_methods(socket);
    init_socket_values(socket, port);
  }
}

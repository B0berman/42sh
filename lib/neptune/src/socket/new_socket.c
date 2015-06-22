/*
** new_socket.c for socket in /home/zack/Projects/neptune_architecte/src/socket
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 21:11:17 2015 Antoine Favarel
** Last update dim. avril 19 21:59:59 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"socket.h"

t_socket	*new_socket(char *addr, int port)
{
  t_socket	*socket;

  if (!(socket = malloc(sizeof(t_socket))))
    return (NULL);
  init_socket(socket, addr, port);
  return (socket);
}

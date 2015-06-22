/*
** delete_socket.c for socket in /home/zack/Projects/neptune_architecte/src/socket
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 21:19:33 2015 Antoine Favarel
** Last update dim. avril 19 21:21:07 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"socket.h"

void		delete_socket(t_socket *socket)
{
  uninit_socket(socket);
  if (socket)
    free(socket);
}

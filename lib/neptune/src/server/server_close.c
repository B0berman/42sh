/*
** server_close.c for server in /home/zack/Projects/neptune_architecte/src/server
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 13:44:02 2015 Antoine Favarel
** Last update jeu. avril 23 15:56:23 2015 Antoine Favarel
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"server.h"

int		server_close(t_server *this)
{
  t_elem	*tmp;
  t_socket	*socket;

  if (!this)
    return (EXIT_FAILURE);
  this->clients->rewind(this->clients);
  while ((tmp = this->clients->next(this->clients)))
    if ((socket = (t_socket*)tmp->mem))
      socket->close(socket);
  close(this->fd);
  return (EXIT_SUCCESS);
}

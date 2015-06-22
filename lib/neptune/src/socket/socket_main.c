/*
** socket_main.c for socket in /home/zack/Projects/neptune_architecte/src/socket
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 21:44:09 2015 Antoine Favarel
** Last update dim. avril 19 22:00:44 2015 Antoine Favarel
*/

#include	"socket.h"

void		*socket_main(void *wrapper)
{
  t_socket	*this;

  this = (t_socket*)wrapper;
  while (this->is_assync)
    this->is_assync = 0;
  return (NULL);
}

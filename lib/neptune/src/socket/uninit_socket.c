/*
** uninit_socket.c for socket in /home/zack/Projects/neptune_architecte/src/socket
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 21:21:10 2015 Antoine Favarel
** Last update dim. avril 19 21:23:20 2015 Antoine Favarel
*/

#include	"socket.h"

void		uninit_socket(t_socket *socket)
{
  uninit_io((void*)socket);
}

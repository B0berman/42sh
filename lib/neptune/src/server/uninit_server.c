/*
** uninit_server.c for server in /home/zack/Projects/neptune_architecte/src/server
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 13:26:45 2015 Antoine Favarel
** Last update lun. avril 20 13:32:13 2015 Antoine Favarel
*/

#include	"server.h"

void		uninit_server(t_server *server)
{
  uninit_socket((void*)server);
  if (server)
    delete_list(server->clients);
}

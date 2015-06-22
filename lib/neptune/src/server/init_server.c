/*
** init_server.c for server in /home/zack/Projects/neptune_architecte/src/server
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 13:10:52 2015 Antoine Favarel
** Last update lun. avril 20 13:25:54 2015 Antoine Favarel
*/

#include	"server.h"

static void	init_server_methods(t_server *server)
{
  server->open = &(server_open);
  server->close = &(server_close);
}

static void	init_server_values(t_server *server)
{
  server->clients = new_list();
  server->gst_connection = NULL;
  server->gst_disconnection = NULL;
  server->is_assync = 1;
}

void		init_server(t_server *server, char *addr, int port)
{
  if (server)
  {
    init_socket((void*)server, addr, port);
    init_server_methods(server);
    init_server_values(server);
  }
}

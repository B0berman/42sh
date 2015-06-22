/*
** delete_server.c for server in /home/zack/Projects/neptune_architecte/src/server
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 13:28:29 2015 Antoine Favarel
** Last update lun. avril 20 13:29:15 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"server.h"

void		delete_server(t_server *server)
{
  uninit_server(server);
  if (server)
    free(server);
}

/*
** new_server.c for server in /home/zack/Projects/neptune_architecte/src/server
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 13:09:07 2015 Antoine Favarel
** Last update lun. avril 20 13:10:48 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"server.h"

t_server	*new_server(char *addr, int port)
{
  t_server	*server;

  if (!(server = malloc(sizeof(t_server))))
    return (NULL);
  init_server(server, addr, port);
  return (server);
}

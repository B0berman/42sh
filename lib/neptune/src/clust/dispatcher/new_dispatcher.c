/*
** new_dispatcher.c for dispatcher in /home/zack/Projects/neptune_architecte/src/clust/dispatcher
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 14:31:52 2015 Antoine Favarel
** Last update sam. avril 25 00:37:06 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"clust/dispatcher.h"

t_dispatcher	*new_dispatcher(char *addr, int port)
{
  t_dispatcher	*dispatcher;

  if (!(dispatcher = malloc(sizeof(t_dispatcher))))
    return (NULL);
  init_dispatcher(dispatcher, addr, port);
  return (dispatcher);
}

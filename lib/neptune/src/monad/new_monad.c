/*
** new_monad.c for monad in /home/zack/Projects/neptune_architecte/src/monad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 16:56:00 2015 Antoine Favarel
** Last update lun. avril 20 17:02:21 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"monad.h"

t_monad		*new_monad(t_list *queue_in, t_list *queue_out)
{
  t_monad	*monad;

  if (!(monad = malloc(sizeof(t_monad))))
    return (NULL);
  init_monad(monad, queue_in, queue_out);
  return (monad);
}

/*
** uninit_list.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 17:19:19 2015 Antoine Favarel
** Last update ven. avril 24 19:04:29 2015 Antoine Favarel
*/

#include	"list.h"

static void	clear(t_list *list)
{
  t_elem	*tmp;

  pthread_cond_signal(&list->is_fill);
  list->lock(list);
  list->rewind(list);
  while ((tmp = list->next(list)))
    list->remove(list, tmp);
  list->unlock(list);
}

void		uninit_list(t_list *list)
{
  if (list)
    clear(list);
}

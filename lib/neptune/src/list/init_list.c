/*
** init_list.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 17:09:12 2015 Antoine Favarel
** Last update sam. avril 25 16:57:46 2015 Antoine Favarel
*/

#include	"neptune/list.h"

static void	init_list_methods(t_list *list)
{
  list->at = &(list_at);
  list->add_first = &(list_add_first);
  list->add_last = &(list_add_last);
  list->check = &(list_check);
  list->push = &(list_push);
  list->pop = &(list_pop);
  list->popret = &(list_popret);
  list->get = &(list_get);
  list->seek = &(list_seek);
  list->rewind = &(list_rewind);
  list->next = &(list_next);
  list->prev = &(list_prev);
  list->put = &(list_put);
  list->remove = &(list_remove);
  list->remove_at = &(list_remove_at);
  list->save = &(list_save);
  list->load = &(list_load);
  list->check = &(list_check);
  list->swap = &(list_swap);
  list->swap_at = &(list_swap_at);
  list->lock = &(list_lock);
  list->unlock = &(list_unlock);
}

static void	init_list_values(t_list *list)
{
  list->first = NULL;
  list->last = NULL;
  list->cursor = NULL;
  pthread_mutexattr_init(&list->attr);
  pthread_mutexattr_settype(&list->attr, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&list->mutex, &list->attr);
  pthread_cond_init(&list->is_fill, NULL);
  list->magic_cmp = 0;
  list->length = 0;
}

void		init_list(t_list *list)
{
  if (list)
  {
    init_list_methods(list);
    init_list_values(list);
  }
}

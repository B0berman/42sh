/*
** list_pop.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 20:44:32 2015 Antoine Favarel
** Last update sam. avril 25 17:00:42 2015 Antoine Favarel
*/

#include	"neptune/list.h"

t_elem		*list_pop(t_list *this)
{
  t_elem	*elem;

  if (!this)
    return (NULL);
  this->lock(this);
  while (this->length == 0)
    pthread_cond_wait(&this->is_fill, &this->mutex);
  elem = this->first;
  if (elem->next)
    elem->next->prev = NULL;
  this->first = elem->next;
  this->length--;
  this->unlock(this);
  return (elem);
}

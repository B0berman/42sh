/*
** list_add_last.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 19:39:56 2015 Antoine Favarel
** Last update dim. avril 19 14:45:54 2015 Antoine Favarel
*/

#include	"list.h"

t_elem		*list_add_last(t_list *this, t_elem *elem)
{
  if (!this || !elem)
    return (NULL);
  this->lock(this);
  if (this->length == 0)
  {
    this->first = elem;
    this->last = elem;
  }
  else
  {
    this->last->next = elem;
    elem->prev = this->last;
    this->last = elem;
  }
  this->length++;
  this->unlock(this);
  pthread_cond_signal(&this->is_fill);
  return (elem);
}

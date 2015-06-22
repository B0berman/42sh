/*
** list_add_first.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 19:22:55 2015 Antoine Favarel
** Last update sam. avril 18 20:46:06 2015 Antoine Favarel
*/

#include	"list.h"

t_elem		*list_add_first(t_list *this, t_elem *elem)
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
    this->first->prev = elem;
    elem->next = this->first;
    this->first = elem;
  }
  this->length++;
  this->unlock(this);
  pthread_cond_signal(&this->is_fill);
  return (elem);
}

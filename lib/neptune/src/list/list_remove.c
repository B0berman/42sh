/*
** list_remove.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 21:43:56 2015 Antoine Favarel
** Last update sam. avril 18 22:18:45 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"list.h"

int		st_first(t_list *this)
{
  this->lock(this);
  this->first = this->first->next;
  delete_elem(this->first->prev);
  this->first->prev = NULL;
  this->length--;
  this->unlock(this);
  return (EXIT_SUCCESS);
}

int		st_last(t_list *this)
{
  this->lock(this);
  this->last = this->last->prev;
  delete_elem(this->last->next);
  this->last->next = NULL;
  this->length--;
  this->unlock(this);
  return (EXIT_SUCCESS);
}

int		st_midle(t_list *this, t_elem *elem)
{
  this->lock(this);
  if (!elem->next || !elem->prev)
    return (EXIT_FAILURE);
  elem->next->prev = elem->prev;
  elem->prev->next = elem->next;
  delete_elem(elem);
  this->length--;
  this->unlock(this);
  return (EXIT_SUCCESS);
}

int		st_lonely(t_list *this, t_elem *elem)
{
  this->lock(this);
  this->first = NULL;
  this->last = NULL;
  this->length = 0;
  delete_elem(elem);
  this->unlock(this);
  return (EXIT_SUCCESS);
}

int		list_remove(t_list *this, t_elem *elem)
{
  if (!this || !elem)
    return (EXIT_FAILURE);
  if (this->length == 1)
    return (st_lonely(this, elem));
  if (elem == this->first)
    return (st_first(this));
  else if (elem == this->last)
    return (st_last(this));
  else
    return (st_midle(this, elem));
}

/*
** list_popret.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 25 16:57:55 2015 Antoine Favarel
** Last update lun. avril 27 15:20:02 2015 Antoine Favarel
*/

#include	"neptune/list.h"

t_elem		*list_popret(t_list *this)
{
  t_elem	*elem;

  if (!this)
    return (NULL);
  this->lock(this);
  if (this->length == 0)
    pthread_cond_wait(&this->is_fill, &this->mutex);
  if (!(elem = this->first))
  {
    this->unlock(this);
    return (NULL);
  }
  if (elem->next)
    elem->next->prev = NULL;
  this->first = elem->next;
  this->length--;
  this->unlock(this);
  return (elem);
}

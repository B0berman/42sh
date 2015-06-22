/*
** list_get.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 25 14:00:46 2015 Antoine Favarel
** Last update sam. avril 25 14:02:56 2015 Antoine Favarel
*/

#include	"neptune/list.h"

t_elem		*list_get(t_list *this, int id)
{
  t_elem	*tmp;

  if (!this)
    return (NULL);
  this->lock(this);
  this->rewind(this);
  while ((tmp = this->next(this)))
    if (tmp->id == id)
    {
      this->unlock(this);
      return (tmp);
    }
  this->unlock(this);
  return (NULL);
}

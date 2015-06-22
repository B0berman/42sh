/*
** list_at.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 13:19:19 2015 Antoine Favarel
** Last update dim. avril 19 15:35:57 2015 Antoine Favarel
*/

#include	"list.h"

t_elem		*list_at(t_list *this, size_t id)
{
  size_t	it;
  t_elem	*elem;

  if (!this)
    return (NULL);
  this->lock(this);
  this->rewind(this);
  it = 0;
  while ((elem = this->next(this)))
    if (it == id)
    {
      this->unlock(this);
      return (elem);
    }
    else
      it++;
  this->unlock(this);
  return (NULL);
}

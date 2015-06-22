/*
** list_put.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 25 14:15:38 2015 Antoine Favarel
** Last update sam. avril 25 17:56:29 2015 Antoine Favarel
*/

#include	"neptune/list.h"

void		list_put(t_list *this, t_list *src)
{
  t_elem	*elem;

  if (this && src)
  {
    src->lock(src);
    src->rewind(src);
    while ((elem = src->next(src)))
      this->push(this, elem);
    src->unlock(src);
  }
}

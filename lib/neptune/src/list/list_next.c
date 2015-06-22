/*
** list_next.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 21:34:12 2015 Antoine Favarel
** Last update sam. avril 18 21:41:32 2015 Antoine Favarel
*/

#include	"list.h"

t_elem		*list_next(t_list *this)
{
  t_elem	*elem;

  if (!this)
    return (NULL);
  elem = this->cursor;
  if (elem)
    this->cursor = elem->next;
  return (elem);
}

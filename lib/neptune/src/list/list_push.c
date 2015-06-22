/*
** list_push.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 20:42:03 2015 Antoine Favarel
** Last update sam. avril 18 20:44:04 2015 Antoine Favarel
*/

#include	"list.h"

t_elem		*list_push(t_list *this, t_elem *elem)
{
  if (!this || !elem)
    return (NULL);
  this->add_last(this, elem);
  return (elem);
}

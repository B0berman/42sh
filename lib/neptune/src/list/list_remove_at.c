/*
** list_remove_at.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 21:57:41 2015 Antoine Favarel
** Last update sam. avril 18 21:59:39 2015 Antoine Favarel
*/

#include	"list.h"

int		list_remove_at(t_list *this, size_t id)
{
  if (!this)
    return (-1);
  return (this->remove(this, this->at(this, id)));
}

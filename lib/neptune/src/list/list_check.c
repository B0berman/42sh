/*
** list_check.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 22:19:08 2015 Antoine Favarel
** Last update dim. avril 19 15:38:50 2015 Antoine Favarel
*/

#include	"list.h"

int		list_check(t_list *this)
{
  t_elem	*elem;
  unsigned int	key;
  unsigned int	hash;

  if (!this)
    return (-1);
  key = 0;
  this->lock(this);
  this->rewind(this);
  while ((elem = this->next(this)))
    key = ((key << 5) + key) ^ elem->check(elem);
  this->unlock(this);
  hash = key % 1596844;
  return ((int) hash);
}

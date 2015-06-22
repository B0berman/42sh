/*
** list_rewind.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 21:32:29 2015 Antoine Favarel
** Last update dim. avril 19 15:38:40 2015 Antoine Favarel
*/

#include	"list.h"

void		list_rewind(t_list *this)
{
  if (this)
  {
    this->lock(this);
    this->cursor = this->first;
    this->unlock(this);
  }
}

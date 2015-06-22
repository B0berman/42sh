/*
** list_swap_at.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 22:36:08 2015 Antoine Favarel
** Last update sam. avril 18 22:39:11 2015 Antoine Favarel
*/

#include	"list.h"

void		list_swap_at(t_list *this, size_t id1, size_t id2)
{
  t_elem	*e1;
  t_elem	*e2;

  e1 = this->at(this, id1);
  e2 = this->at(this, id2);
  this->swap(this, e1, e2);
}

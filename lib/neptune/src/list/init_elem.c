/*
** init_elem.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 16:43:41 2015 Antoine Favarel
** Last update dim. avril 19 16:50:08 2015 Antoine Favarel
*/

#include	"list.h"

void		init_elem_methods(t_elem *elem)
{
  elem->dup = &(elem_dup);
}

void		init_elem_values(t_elem *elem)
{
  elem->next = NULL;
  elem->prev = NULL;
}

void		init_elem(t_elem *elem)
{
  if (elem)
  {
    init_data((void*)elem);
    init_elem_methods(elem);
    init_elem_values(elem);
  }
}

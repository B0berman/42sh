/*
** new_init_static_elem.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 20:36:26 2015 Antoine Favarel
** Last update sam. avril 18 20:39:14 2015 Antoine Favarel
*/

#include	"list.h"

t_elem		*new_init_static_elem(void *mem, size_t size)
{
  t_elem	*elem;

  if (!(elem = new_elem()))
    return (NULL);
  elem->set_mem(elem, mem, size);
  return (elem);
}

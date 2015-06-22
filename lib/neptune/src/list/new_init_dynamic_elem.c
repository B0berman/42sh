/*
** new_init_dynamic_elem.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 20:39:28 2015 Antoine Favarel
** Last update sam. avril 25 17:01:22 2015 Antoine Favarel
*/

#include	"list.h"

t_elem		*new_init_dynamic_elem(void *mem, size_t size)
{
  t_elem	*elem;

  if (!(elem = new_elem()))
    return (NULL);
  elem->set_dupmem(elem, mem, size);
  return (elem);
}

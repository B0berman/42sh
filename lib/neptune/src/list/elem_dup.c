/*
** elem_dup.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 17:27:37 2015 Antoine Favarel
** Last update sam. avril 18 23:02:26 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"list.h"

t_elem		*elem_dup(t_elem *this)
{
  if (!this)
    return (NULL);
  return (_mush(this->mem, this->size_of_mem));
}

/*
** list_load.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 22:06:42 2015 Antoine Favarel
** Last update dim. avril 19 16:19:54 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"list.h"

int		list_load(t_list *this, t_io *stream)
{
  int		i;
  size_t	length;
  t_elem	*elem;

  if (!this || !stream)
    return (EXIT_FAILURE);
  i = -1;
  stream->gets(stream, (char *)&length, sizeof(size_t));
  stream->gets(stream, (char *)&this->magic_cmp, sizeof(int));
  while (++i < (int) length)
  {
    if ((elem = new_elem()))
      elem->load(elem, stream);
    this->push(this, elem);
  }
  if (this->magic_cmp != this->check(this))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

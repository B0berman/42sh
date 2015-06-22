/*
** list_save.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 22:00:53 2015 Antoine Favarel
** Last update dim. avril 19 16:19:50 2015 Antoine Favarel
*/

#include	"list.h"

static void	save_in_stream(t_list *this, t_io *stream)
{
  t_elem	*elem;

  this->lock(this);
  this->magic_cmp = this->check(this);
  stream->puts(stream, (char *)&this->length, sizeof(size_t));
  stream->puts(stream, (char *)&this->magic_cmp, sizeof(int));
  this->rewind(this);
  while ((elem = this->next(this)))
    elem->save(elem, stream);
  this->unlock(this);
}

void		list_save(t_list *this, t_io *stream)
{
  if (this && stream)
    save_in_stream(this, stream);
}

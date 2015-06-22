/*
** data_save.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 14:56:03 2015 Antoine Favarel
** Last update sam. avril 25 14:06:01 2015 Antoine Favarel
*/

#include	<stdio.h>
#include	"neptune/data.h"

static void	save_in_stream(t_data *this, t_io *stream)
{
  this->lock(this);
  this->magic_cmp = this->check(this);
  stream->lock(stream);
  stream->puts(stream, (char *)&this->size_of_mem, sizeof(size_t));
  stream->puts(stream, (char *)&this->magic_cmp, sizeof(int));
  stream->puts(stream, (char *)&this->id, sizeof(int));
  stream->puts(stream, this->mem, this->size_of_mem);
  stream->unlock(stream);
  this->unlock(this);
}

void		data_save(t_data *this, t_io *stream)
{
  if (this && stream)
    save_in_stream(this, stream);
}

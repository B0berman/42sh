/*
** data_load.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 15:20:51 2015 Antoine Favarel
** Last update mer. avril 29 16:29:12 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/data.h"

static int	ret_error(t_io *stream)
{
  stream->close(stream);
  return (EXIT_FAILURE);
}

int		data_load(t_data *this, t_io *stream)
{
  if (!this || !stream)
    return (EXIT_FAILURE);
  if (stream->gets(stream, (char *)&this->size_of_mem, sizeof(size_t))
      ==  EXIT_FAILURE)
    return (ret_error(stream));
  if (!(this->mem = malloc(this->size_of_mem)))
    return (ret_error(stream));
  if (stream->gets(stream, (char *)&this->magic_cmp, sizeof(int))
      == EXIT_FAILURE)
    return (ret_error(stream));
  if (stream->gets(stream, (char *)&this->id, sizeof(int))
      == EXIT_FAILURE)
    return (ret_error(stream));
  this->is_local = 1;
  if (stream->gets(stream, this->mem, this->size_of_mem) == EXIT_FAILURE)
    return (ret_error(stream));
  if (this->magic_cmp != this->check(this))
    return (ret_error(stream));
  return (EXIT_SUCCESS);
}

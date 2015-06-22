/*
** data_set_dupmem.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 11:48:57 2015 Antoine Favarel
** Last update ven. avril 17 16:02:57 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"data.h"

static int	memdump(t_data *this, void *mem, size_t size)
{
  char		*wrapper;
  char		*buffer;
  int		i;

  wrapper = mem;
  if (!(buffer = malloc(size)))
    return (-1);
  i = -1;
  while (++i < (int) size)
    buffer[i] = wrapper[i];
  this->mem = buffer;
  this->size_of_mem = size;
  this->is_local = 1;
  return (0);
}

void		data_set_dupmem(t_data *this, void *mem, size_t size)
{
  if (this != NULL && mem != NULL)
    memdump(this, mem, size);
}

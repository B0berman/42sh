/*
** io_puts.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 03:15:09 2015 Antoine Favarel
** Last update sam. avril 25 00:48:23 2015 Antoine Favarel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"io.h"

int		io_puts(t_io *this, char *buffer, size_t size)
{
  if (!this || !buffer || this->fd == -1)
    return (EXIT_FAILURE);
  this->lock(this);
  if (write(this->fd, buffer, size) == -1)
  {
    this->unlock(this);
    return (EXIT_FAILURE);
  }
  this->unlock(this);
  return (EXIT_SUCCESS);
}

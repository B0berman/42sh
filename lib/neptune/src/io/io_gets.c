/*
** io_gets.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 03:19:00 2015 Antoine Favarel
** Last update mer. avril 29 16:30:06 2015 Antoine Favarel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"neptune/io.h"

int		io_gets(t_io *this, char *buffer, size_t size)
{
  int		ret;
  size_t	byteread;

  byteread = 0;
  if (!this || !buffer || this->fd == -1)
    return (EXIT_FAILURE);
  while (byteread < size)
  {
    ret = read(this->fd, &buffer[byteread], size - byteread);
    if (ret < 1)
      return (EXIT_FAILURE);
    byteread += ret;
  }
  return (EXIT_SUCCESS);
}

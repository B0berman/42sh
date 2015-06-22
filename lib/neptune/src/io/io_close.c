/*
** io_close.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 03:29:21 2015 Antoine Favarel
** Last update ven. avril 17 03:31:21 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"io.h"

int		io_close(t_io *this)
{
  if (!this || this->fd == -1)
    return (EXIT_FAILURE);
  if (close(this->fd) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

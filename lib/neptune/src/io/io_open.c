/*
** io_open.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 03:08:53 2015 Antoine Favarel
** Last update ven. avril 17 03:58:33 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"io.h"

int		io_open(t_io *this)
{
  if (!this)
    return (EXIT_FAILURE);
  if ((this->fd = open(this->src,
	  O_RDWR | O_CREAT,
	  S_IRUSR | S_IWUSR)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

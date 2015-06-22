/*
** init_io.c for io in /home/zack/neptune/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 16:56:54 2015 Antoine Favarel
** Last update jeu. mai 21 12:32:52 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"io.h"

static void	init_io_methods(t_io *io)
{
  io->open = &(io_open);
  io->puts = &(io_puts);
  io->gets = &(io_gets);
  io->nextline = &(io_nextline);
  io->close = &(io_close);
  io->assync = &(io_assync);
  io->lock = &(io_lock);
  io->unlock = &(io_unlock);
}

static void	init_io_values(t_io *io, char *src)
{
  io->fd = -1;
  io->src = src;
  io->buffsize = 4048*8;
  io->buffer = malloc(sizeof(char) * (io->buffsize + 1));
  io->buffer[0] = '\0';
  io->buffer[io->buffsize] = '\0';
  io->is_assync = 0;
  pthread_mutexattr_init(&io->attr);
  pthread_mutexattr_settype(&io->attr, PTHREAD_MUTEX_RECURSIVE);
  pthread_mutex_init(&io->mutex, &io->attr);
}

void		init_io(t_io *io, char *src)
{
  if (io)
  {
    init_io_methods(io);
    init_io_values(io, src);
  }
}


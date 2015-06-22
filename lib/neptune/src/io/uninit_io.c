/*
** uninit_io.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 17:04:55 2015 Antoine Favarel
** Last update dim. avril 19 17:05:54 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"io.h"

void		uninit_io(t_io *io)
{
  if (io && io->buffer)
    free(io->buffer);
}

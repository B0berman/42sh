/*
** delete_io.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 02:45:18 2015 Antoine Favarel
** Last update dim. avril 19 17:06:25 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"io.h"

void		delete_io(t_io *io)
{
  uninit_io(io);
  if (io)
    free(io);
}

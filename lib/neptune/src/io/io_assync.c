/*
** io_assync.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 03:28:13 2015 Antoine Favarel
** Last update ven. avril 17 10:39:46 2015 Antoine Favarel
*/

#include	"io.h"

void		io_assync(t_io *this, int on_off)
{
  if (this)
    this->is_assync = on_off;
}

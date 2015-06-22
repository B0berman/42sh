/*
** io_unlock.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 16:39:39 2015 Antoine Favarel
** Last update ven. avril 17 16:40:07 2015 Antoine Favarel
*/

#include	"io.h"

void		io_unlock(t_io *this)
{
  if (this)
    pthread_mutex_unlock(&this->mutex);
}

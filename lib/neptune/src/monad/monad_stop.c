/*
** monad_stop.c for monad in /home/zack/Projects/neptune_architecte/src/monad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 17:50:48 2015 Antoine Favarel
** Last update dim. avril 26 16:24:00 2015 Antoine Favarel
*/

#include	"neptune/monad.h"

void		monad_stop(t_monad *this)
{
  if (this)
    pthread_cancel(this->main);
}

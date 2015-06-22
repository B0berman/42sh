/*
** monad_start.c for monad in /home/zack/Projects/neptune_architecte/src/monad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 17:48:32 2015 Antoine Favarel
** Last update dim. avril 26 16:24:38 2015 Antoine Favarel
*/

#include	"neptune/monad.h"

static void	st_start(t_monad *this)
{
  pthread_create(&this->main, NULL, &(monad_main), (void*)this);
}

void		monad_start(t_monad *this)
{
  if (this && this->queue_in && this->queue_out && this->gst_actor)
    st_start(this);
}

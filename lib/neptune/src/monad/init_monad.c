/*
** init_monad.c for monad in /home/zack/Projects/neptune_architecte/src/monad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 17:02:25 2015 Antoine Favarel
** Last update lun. avril 20 17:10:08 2015 Antoine Favarel
*/

#include	"monad.h"

static void	init_monad_methods(t_monad *this)
{
  this->start = &(monad_start);
  this->stop = &(monad_stop);
  this->update = &(monad_update);
}

static void	init_monad_values(t_monad *this, t_list *in, t_list *out)
{
  this->queue_in = in;
  this->queue_out = out;
  this->data = NULL;
}

void		init_monad(t_monad *this, t_list *q_in, t_list *q_out)
{
  if (this)
  {
    init_monad_methods(this);
    init_monad_values(this, q_in, q_out);
  }
}

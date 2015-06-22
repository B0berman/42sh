/*
** manager_update.c for manager in /home/zack/Projects/neptune_architecte/src/clust/manager
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 13:51:11 2015 Antoine Favarel
** Last update mar. avril 21 18:39:25 2015 Antoine Favarel
*/

#include	"clust/manager.h"

void		manager_update(t_manager *this, t_list *data)
{
  t_elem	*elem;
  t_monad	*monad;

  this->monads->rewind(this->monads);
  while ((elem = this->monads->next(this->monads)))
    if ((monad = elem->mem))
      monad->data = data;
}

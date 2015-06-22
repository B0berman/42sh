/*
** uninit_manager.c for manager in /home/zack/Projects/neptune_architecte/src/clust/manager
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. avril 23 16:10:04 2015 Antoine Favarel
** Last update jeu. avril 23 16:14:42 2015 Antoine Favarel
*/

#include	"clust/manager.h"

void		uninit_manager(t_manager *manager)
{
  t_elem	*monad;

  if (manager)
  {
    uninit_socket((t_socket*)manager);
    manager->monads->rewind(manager->monads);
    while ((monad = manager->monads->next(manager->monads)))
      if (monad->mem)
	((t_monad *)monad->mem)->stop((t_monad*)monad->mem);
    delete_list(manager->data);
    delete_list(manager->monads);
  }
}

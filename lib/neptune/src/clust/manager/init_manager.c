/*
** init_manager.c for manager in /home/zack/Projects/neptune_architecte/src/clust/manager
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 10:42:13 2015 Antoine Favarel
** Last update mer. avril 29 14:50:28 2015 Antoine Favarel
*/

#include	"neptune/clust/manager.h"

static void	init_manager_methods(t_manager *manager)
{
  manager->open = &(manager_open);
  manager->update = &(manager_update);
}

static void	init_manager_values(t_manager *manager, int coexiam)
{
  manager->coexiam = coexiam;
  manager->monads = new_list();
  manager->in = new_list();
  manager->out = new_list();
  manager->actor = NULL;
  pthread_cond_init(&manager->is_akn, NULL);
}

void		init_manager(t_manager *m, char *ad, int p, int c)
{
  if (m)
  {
    init_socket((t_socket*)m, ad, p);
    init_manager_methods(m);
    init_manager_values(m, c);
  }
}

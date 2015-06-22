/*
** list_swap.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 22:24:02 2015 Antoine Favarel
** Last update sam. avril 18 22:35:44 2015 Antoine Favarel
*/

#include	"list.h"

static void	st_swapon(t_elem *e1, t_elem *e2)
{
  size_t	size_of_mem_tmp;
  void		*mem_tmp;
  int		is_local_tmp;

  size_of_mem_tmp = e1->size_of_mem;
  mem_tmp = e1->mem;
  is_local_tmp = e1->is_local;
  e1->size_of_mem = e2->size_of_mem;
  e1->mem = e2->mem;
  e1->is_local = e2->is_local;
  e1->magic_cmp = e1->check(e1);
  e2->size_of_mem = size_of_mem_tmp;
  e2->mem = mem_tmp;
  e2->is_local = is_local_tmp;
  e2->magic_cmp = e2->check(e2);
}

void		list_swap(t_list *this, t_elem *e1, t_elem *e2)
{
  if (this && e1 && e2)
  {
    this->lock(this);
    st_swapon(e1, e2);
    this->unlock(this);
  }
}

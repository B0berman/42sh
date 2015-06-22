/*
** data_x.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 15:46:50 2015 Antoine Favarel
** Last update ven. avril 17 16:50:20 2015 Antoine Favarel
*/

#include	"data.h"

static void	writing(t_data *this, size_t it, void *buff, size_t size)
{
  int		i;
  char		*wrapper;
  char		*wrapper_2;

  wrapper = this->mem;
  wrapper_2 = buff;
  i = -1;
  this->lock(this);
  while (++i < (int) size)
    wrapper[(it + i) % this->size_of_mem] = wrapper_2[i];
  this->unlock(this);
}

void		data_x(t_data *this, size_t it, void *buff, size_t size)
{
  if (this && buff && size > 0)
    writing(this, it, buff, size);
}

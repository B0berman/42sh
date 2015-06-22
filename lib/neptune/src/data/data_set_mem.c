/*
** data_set_mem.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 11:46:16 2015 Antoine Favarel
** Last update ven. avril 17 11:48:14 2015 Antoine Favarel
*/

#include	"data.h"

void		data_set_mem(t_data *this, void *mem, size_t size)
{
  if (this)
  {
    this->size_of_mem = size;
    this->mem = mem;
    this->is_local = 0;
  }
}

/*
** data_check.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 15:32:32 2015 Antoine Favarel
** Last update ven. avril 17 16:03:42 2015 Antoine Favarel
*/

#include	"data.h"

int		data_check(t_data *this)
{
  int		i;
  unsigned int	key;
  unsigned int	hash;
  char		*wrapper;

  i = -1;
  wrapper = this->mem;
  key = 0;
  if (!this)
    return (-1);
  while (++i < (int) this->size_of_mem)
    key = ((key << 5) + key) ^ (int)wrapper[i];
  hash = key % 1456924;
  return ((int) hash);
}

/*
** data_lock.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 16:34:47 2015 Antoine Favarel
** Last update ven. avril 17 16:36:48 2015 Antoine Favarel
*/

#include	"data.h"

void		data_lock(t_data *this)
{
  if (this)
    pthread_mutex_lock(&this->mutex);
}

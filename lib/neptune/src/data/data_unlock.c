/*
** data_unlock.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 16:36:53 2015 Antoine Favarel
** Last update ven. avril 17 16:37:23 2015 Antoine Favarel
*/

#include	"data.h"

void		data_unlock(t_data *this)
{
  if (this)
    pthread_mutex_unlock(&this->mutex);
}

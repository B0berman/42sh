/*
** list_unlock.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 13:32:04 2015 Antoine Favarel
** Last update dim. avril 19 15:25:58 2015 Antoine Favarel
*/

#include	<stdio.h>
#include	"list.h"

void		list_unlock(t_list *this)
{
  if (this)
    pthread_mutex_unlock(&this->mutex);
}

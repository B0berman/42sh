/*
** delete_data.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 11:42:33 2015 Antoine Favarel
** Last update dim. avril 19 16:40:56 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"data.h"

void		delete_data(t_data *data)
{
  uninit_data(data);
  if (data)
    free(data);
}

/*
** uninit_data.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 16:39:25 2015 Antoine Favarel
** Last update dim. avril 19 16:40:12 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"data.h"

void		uninit_data(t_data *data)
{
  if (data && data->is_local && data->mem)
    free(data->mem);
}

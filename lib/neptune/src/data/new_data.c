/*
** new_data.c for data in /home/zack/Projects/neptune_architecte/src/data
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 11:36:46 2015 Antoine Favarel
** Last update dim. avril 19 16:39:14 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"data.h"

t_data		*new_data()
{
  t_data	*data;

  if (!(data = malloc(sizeof(t_data))))
    return (NULL);
  init_data(data);
  return (data);
}

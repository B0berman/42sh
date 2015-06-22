/*
** new_elem.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 17:13:55 2015 Antoine Favarel
** Last update dim. avril 19 16:50:06 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"list.h"

t_elem		*new_elem()
{
  t_elem	*elem;

  if (!(elem = malloc(sizeof(t_elem))))
    return (NULL);
  init_elem(elem);
  return (elem);
}

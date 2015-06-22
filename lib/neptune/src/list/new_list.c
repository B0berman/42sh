/*
** new_list.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 12:58:23 2015 Antoine Favarel
** Last update dim. avril 19 17:16:23 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"list.h"

t_list		*new_list()
{
  t_list	*list;

  if (!(list = malloc(sizeof(t_list))))
    return (NULL);
  init_list(list);
  return (list);
}

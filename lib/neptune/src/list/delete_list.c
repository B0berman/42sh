/*
** delete_list.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 22:41:40 2015 Antoine Favarel
** Last update dim. avril 19 17:23:17 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"list.h"

void		delete_list(t_list *list)
{
  uninit_list(list);
  if (list)
    free(list);
}

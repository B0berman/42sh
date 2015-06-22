/*
** delete_elem.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 17:24:40 2015 Antoine Favarel
** Last update dim. avril 19 16:51:51 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"list.h"

void		delete_elem(t_elem *elem)
{
  uninit_elem(elem);
  if (elem)
    free(elem);
}

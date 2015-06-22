/*
** uninit_elem.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 16:50:54 2015 Antoine Favarel
** Last update dim. avril 19 17:18:24 2015 Antoine Favarel
*/

#include	"list.h"

void		uninit_elem(t_elem *elem)
{
  if (elem)
    uninit_data((void*)elem);
}

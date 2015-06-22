/*
** list_seek.c for list in /home/zack/Projects/neptune_architecte/src/list
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. avril 18 21:05:48 2015 Antoine Favarel
** Last update sam. avril 18 23:25:03 2015 Antoine Favarel
*/

#include	"list.h"

t_elem		*st_cur(t_list *list, t_elem *cur, size_t id)
{
  int		i;

  i = 0;
  if (((int)id) < 0)
    while (--i > (int) id && cur)
      cur = cur->prev;
  else
    while (++i < (int) id && cur)
      cur = cur->next;
  return (cur);
}

void		list_seek(t_list *this, size_t id, char pos)
{
  if (this && pos == LIST_SET)
    this->cursor = this->at(this, id);
  else if (this && pos == LIST_CUR)
    this->cursor = st_cur(this, this->cursor, id);
  else if (this && pos == LIST_END)
    this->cursor = st_cur(this, this->last, id);
}

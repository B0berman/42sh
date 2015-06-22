/*
** sm_split.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. févr. 24 10:55:01 2015 Antoine Favarel
** Last update jeu. avril 23 17:08:01 2015 Antoine Favarel
*/

#include	"strmut.h"

t_list		*sm_split(char *str, char spliter)
{
  int		i;
  int		j;
  t_list	*list;
  char		*n_str;

  i = -1;
  j = 0;
  if (!str)
    return (NULL);
  if (!(list = new_list()))
    return (NULL);
  while (str[++i])
    if (str[i] == spliter)
    {
      n_str = sm_dupn(&str[j], i - j);
      list->push(list, _wrap(n_str, sm_len(n_str)));
      j = i + 1;
    }
  if (j != i)
    list->push(list, _wrap(sm_dup(&str[j]), sm_len(&str[j])));
  return (list);
}

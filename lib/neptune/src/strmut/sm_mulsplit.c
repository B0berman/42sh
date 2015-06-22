/*
** sm_mulsplit.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. févr. 24 11:12:59 2015 Antoine Favarel
** Last update jeu. avril 23 17:08:51 2015 Antoine Favarel
*/

#include	"strmut.h"

t_list		*sm_mulsplit(char *str, char *spliters)
{
  int		i;
  int		j;
  t_list	*list;
  char		*n_str;

  i = -1;
  j = 0;
  if (!str || !spliters)
    return (NULL);
  if (!(list = new_list()))
    return (NULL);
  while (str[++i])
    if (sm_is_strcontainc(spliters, str[i]))
    {
      n_str = sm_dupn(&str[j], i - j);
      list->push(list, _wrap(n_str, sm_len(n_str)));
      j = i + 1;
    }
  if (j != i)
    list->push(list, _wrap(sm_dup(&str[j]), sm_len(&str[j])));
  return (list);
}

/*
** tree.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 15:05:17 2015 Antoine Favarel
** Last update dim. mai 24 22:00:53 2015 Antoine Favarel
*/

#include		"coquillage.h"

static int		st_getprio(t_execute *execute)
{
  if (execute->id == BUILTIN
      || execute->id == CMD_ARG)
    return (0);
  else if (execute->id == PIPE)
    return (1);
  else if (execute->id == OR
      || execute->id == AND)
    return (2);
  else if (execute->id == SEMICOLON)
    return (3);
  return (-1);
}

static t_execute	*st_maxprio(t_list *stack)
{
  int			last_prio;
  t_execute		*last_max;
  t_elem		*tmp;

  stack->rewind(stack);
  last_max = NULL;
  last_prio = -1;
  while ((tmp = stack->next(stack)))
    if (st_getprio((t_execute*)tmp->mem) > last_prio)
    {
      last_max = (t_execute*)tmp->mem;
      last_prio = st_getprio((t_execute*)tmp->mem);
    }
  return (last_max);
}

static t_list		*st_prevlist(t_list *stack, t_execute *execute)
{
  t_elem		*tmp;
  t_execute		*tmp_x;
  t_list		*n_list;

  n_list = new_list();
  stack->rewind(stack);
  while ((tmp = stack->next(stack))
      && (tmp_x = (t_execute*)tmp->mem) != execute)
    n_list->push(n_list, _wrap(tmp_x, sizeof(t_execute)));
  return (n_list);
}

static t_list		*st_nextlist(t_list *stack, t_execute *execute)
{
  t_elem		*tmp;
  t_execute		*tmp_x;
  t_list		*n_list;

  n_list = new_list();
  stack->rewind(stack);
  while ((tmp = stack->next(stack))
      && (tmp_x = (t_execute*)tmp->mem) != execute);
  while ((tmp = stack->next(stack))
      && (tmp_x = (t_execute*)tmp->mem))
    n_list->push(n_list, _wrap(tmp_x, sizeof(t_execute)));
  return (n_list);
}

t_node			*tree(t_list *stack)
{
  t_node		*node;
  t_execute		*execute;

  execute = st_maxprio(stack);
  if (execute == NULL)
    return (NULL);
  node = new_node(execute);
  node->left = tree(st_prevlist(stack, execute));
  node->right = tree(st_nextlist(stack, execute));
  return (node);
}

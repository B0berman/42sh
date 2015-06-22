/*
** getexecute.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 14:32:03 2015 Antoine Favarel
** Last update jeu. mai 21 22:57:54 2015 Antoine Favarel
*/

#include	"coquillage.h"
#include	"neptune/strmut.h"

static void	st_red(t_execute *execute, t_list *stack, t_token *token)
{
  t_token	*n_token;

  n_token = NULL;
  if (stack->first->next)
    n_token = (t_token*)stack->first->next->mem;
  execute->is_redpresent = 1;
  execute->redir = token->id;
  execute->red_value = (n_token ? n_token->value : "");
  stack->pop(stack);
  stack->pop(stack);
}

static void	st_recexecute(t_execute *execute, t_list *stack)
{
  t_token	*token;
  t_token	*n_token;

  n_token = NULL;
  while (stack->first)
  {
    token = (t_token*)stack->first->mem;
    if (token->id == CMD_ARG || token->id == BUILTIN)
      execute->params->push(execute->params,
	  _wrap(token->value, sm_len(token->value)));
    else if (token->id == D_REDL || token->id == D_REDR
	|| token->id == REDL || token->id == REDR)
    {
      st_red(execute, stack, token);
      return ;
    }
    else
      return ;
    stack->pop(stack);
  }
}

t_execute	*getexecute(t_list *stack)
{
  t_execute	*execute;
  t_token	*token;

  if (stack->length == 0)
    return (NULL);
  token = (t_token*)stack->pop(stack)->mem;
  execute = new_execute(token->id, token->value);
  if (execute->id == BUILTIN || execute->id == CMD_ARG)
    st_recexecute(execute, stack);
  return (execute);
}

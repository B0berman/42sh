/*
** translate.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 15:24:37 2015 Antoine Favarel
** Last update dim. mai 24 22:00:29 2015 Antoine Favarel
*/

#include	<stdio.h>
#include	"coquillage.h"

static int	st_error(t_node *ast, t_system *s)
{
  s->out->fd = 2;
  s->print(s, "coquillage: syntax_error: ");
  s->print(s, "['%s'] expected two operand\n", ast->execute->label);
  s->out->fd = 1;
  return (0);
}

static int	st_iscorrect(t_node *ast, t_system *s)
{
  t_id		id;

  id = ast->execute->id;
  if ((id == CMD_ARG || id == BUILTIN)
      && (ast->left || ast->right))
    return (0);
  else if ((id == CMD_ARG || id == BUILTIN))
    return (1);
  else if (!(ast->left && ast->right))
    return (st_error(ast, s));
  return ((!st_iscorrect(ast->left, s) ? 0 : st_iscorrect(ast->right, s)));
}

t_node		*translate(char *string, t_system *sys)
{
  t_node	*node;
  t_list	*stack;

  if (!(stack = tokenize(string, sys)))
    return (NULL);
  if (!(stack = lexer(stack)))
    return (NULL);
  if (!(node = tree(stack)))
    return (NULL);
  if (!st_iscorrect(node, new_system(0, NULL, NULL)))
    return (NULL);
  return (node);
}

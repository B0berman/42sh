/*
** execute.c for coquillage in /home/zack/Epitech/PSU_2014_42sh/src/coquillage
** 
** Made by Antoine Meuniez
** Login   <meuniez_k@epitech.net>
** 
** Started on  mer. mai 20 14:54:15 2015 Antoine Meuniez
** Last update Mon Jun 22 13:44:13 2015 walbec_h
*/

#include	"coquillage.h"

int		execute(t_system *sys, t_node *ast)
{
  t_execute	*x;

  x = ast->execute;
  if (x->id == PIPE)
    return (c_pipe(sys, ast));
  else if (x->id == OR)
    return (c_or(sys, ast));
  else if (x->id == AND)
    return (c_and(sys, ast));
  else if (x->id == SEMICOLON)
    return (c_semicolon(sys, ast));
  else
    return (c_norm(sys, x));
}

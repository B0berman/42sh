/*
** lexer.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by wachow_a
** Login   <wachow_a@epitech.net>
** 
** Started on  jeu. mai 21 15:00:50 2015 wachow_a
** Last update dim. mai 24 21:59:25 2015 Antoine Favarel
*/

#include	"coquillage.h"

t_list		*lexer(t_list *stack)
{
  t_list	*executes;
  t_execute	*execute;

  executes = new_list();
  while ((execute = getexecute(stack)))
    executes->push(executes, _wrap(execute, sizeof(t_execute)));
  return (executes);
}

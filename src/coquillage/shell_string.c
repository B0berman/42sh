/*
** shell_string.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 14:28:04 2015 Antoine Favarel
** Last update dim. mai 24 02:13:52 2015 Antoine Favarel
*/

#include	"coquillage.h"

int		shell_string(t_system *system, char *value)
{
  t_node	*ast;

  if (!(ast = translate(value, system)))
    return (1);
  return (execute(system, ast));
}

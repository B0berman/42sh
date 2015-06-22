/*
** c_or.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Meuniez
** Login   <meuniez_k@epitech.net>
** 
** Started on  jeu. mai 21 11:19:16 2015 Antoine Meuniez
** Last update dim. mai 24 21:54:39 2015 Antoine Favarel
*/

#include	"coquillage.h"

int		c_or(t_system *sys, t_node *ast)
{
  int		ret;

  if ((ret = execute(sys, ast->left)) == 0
      || (ret = execute(sys, ast->right)) == 0)
    return (0);
  return (ret);
}

/*
** c_and.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 11:26:58 2015 Antoine Favarel
** Last update jeu. mai 21 11:43:40 2015 Antoine Favarel
*/

#include	"coquillage.h"

int		c_and(t_system *sys, t_node *ast)
{
  int		ret;

  if ((ret = execute(sys, ast->left)) == 0
      && (ret = execute(sys, ast->right)) == 0)
    return (0);
  return (ret);
}

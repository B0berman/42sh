/*
** c_semicolon.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 11:34:57 2015 Antoine Favarel
** Last update jeu. mai 21 11:37:28 2015 Antoine Favarel
*/

#include	"coquillage.h"

int		c_semicolon(t_system *sys, t_node *ast)
{
  execute(sys, ast->left);
  return (execute(sys, ast->right));
}

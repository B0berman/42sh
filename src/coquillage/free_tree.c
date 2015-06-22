/*
** free_tree.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mer. mai 20 14:45:08 2015 Antoine Favarel
** Last update mer. mai 20 14:53:57 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"coquillage.h"

void		free_tree(t_node *node)
{
  if (node->left)
    free_tree(node->left);
  if (node->right)
    free_tree(node->right);
  free_node(node);
}

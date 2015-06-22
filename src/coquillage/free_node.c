/*
** free_node.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mer. mai 20 14:43:39 2015 Antoine Favarel
** Last update mer. mai 20 14:45:05 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"coquillage.h"

void		free_node(t_node *node)
{
  free_execute(node->execute);
  free(node);
}

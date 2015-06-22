/*
** new_node.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. mai 18 11:42:22 2015 Antoine Favarel
** Last update jeu. mai 21 22:23:52 2015 Antoine Favarel
*/

#include	<stdlib.h>

#include	"coquillage.h"

t_node		*new_node(t_execute *execute)
{
  t_node	*node;

  if (!(node = malloc(sizeof(t_node))))
    return (NULL);
  node->execute = execute;
  return (node);
}

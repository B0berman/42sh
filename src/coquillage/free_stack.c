/*
** free_stack.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mer. mai 20 14:51:09 2015 Antoine Favarel
** Last update mer. mai 20 14:54:09 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"coquillage.h"

void		free_stack(t_list *stack)
{
  delete_list(stack);
}

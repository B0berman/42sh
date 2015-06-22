/*
** free_execute.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mer. mai 20 14:41:16 2015 Antoine Favarel
** Last update mer. mai 20 14:43:32 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"coquillage.h"

void		free_execute(t_execute *execute)
{
  delete_list(execute->params);
  free(execute);
}

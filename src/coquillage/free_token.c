/*
** free_token.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Meuniez
** Login   <meuniez_k@epitech.net>
** 
** Started on  mer. mai 20 14:33:21 2015 Antoine Meuniez
** Last update dim. mai 24 21:57:27 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"coquillage.h"

void		free_token(t_token *token)
{
  free(token);
}

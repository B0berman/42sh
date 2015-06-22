/*
** new_token.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. mai 18 11:43:50 2015 Antoine Favarel
** Last update jeu. mai 21 22:23:56 2015 Antoine Favarel
*/

#include	<stdlib.h>

#include	"coquillage.h"

t_token		*new_token(t_id id, char *value)
{
  t_token	*token;

  if (!(token = malloc(sizeof(t_token))))
    return (NULL);
  token->id = id;
  token->value = value;
  return (token);
}

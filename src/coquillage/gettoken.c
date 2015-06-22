/*
** gettoken.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon May 18 17:58:45 2015 walbec_h
** Last update jeu. mai 21 22:21:54 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"coquillage.h"

t_token		*gettoken(char *value)
{
  t_token	*token;

  if (!(token = malloc(sizeof(t_token))))
    return (NULL);
  token->id = getid(value);
  token->value = value;
  return (token);
}

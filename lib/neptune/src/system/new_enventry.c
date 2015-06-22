/*
** new_enventry.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:30:14 2015 Antoine Favarel
** Last update dim. avril 26 18:34:39 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/system.h"

t_enventry	*new_enventry(char *key, char *value)
{
  t_enventry	*enventry;

  if (!(enventry = malloc(sizeof(t_enventry))))
    return (NULL);
  enventry->key = key;
  enventry->value = value;
  return (enventry);
}

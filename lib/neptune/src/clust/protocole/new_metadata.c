/*
** new_metadata.c for protocole in /home/zack/Projects/neptune_architecte/src/clust/protocole
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 17:10:08 2015 Antoine Favarel
** Last update mar. avril 21 17:11:59 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"clust/protocole.h"

t_metadata	*new_metadata(t_role role, t_desc desc)
{
  t_metadata	*meta;

  if (!(meta = malloc(sizeof(t_metadata))))
    return (NULL);
  meta->role = role;
  meta->desc = desc;
  return (meta);
}

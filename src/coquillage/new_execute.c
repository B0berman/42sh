/*
** new_execute.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 22:22:14 2015 Antoine Favarel
** Last update jeu. mai 21 22:23:41 2015 Antoine Favarel
*/

#include	<stdlib.h>

#include	"coquillage.h"

t_execute	*new_execute(t_id id, char *label)
{
  t_execute	*execute;

  if (!(execute = malloc(sizeof(t_execute))))
    return (NULL);
  execute->id = id;
  execute->label = label;
  execute->params = new_list();
  execute->is_redpresent = 0;
  return (execute);
}

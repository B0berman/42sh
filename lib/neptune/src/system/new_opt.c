/*
** new_opt.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:26:48 2015 Antoine Favarel
** Last update dim. avril 26 18:30:09 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/system.h"

t_opt		*new_opt(char *option, int is_enable, char *value)
{
  t_opt		*opt;

  if (!(opt = malloc(sizeof(t_opt))))
    return (NULL);
  opt->option = option;
  opt->is_enable = is_enable;
  opt->value = value;
  return (opt);
}

/*
** system_st_initopts.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:47:59 2015 Antoine Favarel
** Last update dim. avril 26 22:48:33 2015 Antoine Favarel
*/

#include	"neptune/system.h"
#include	"neptune/strmut.h"

t_opt		*st_getopt(char *arg)
{
  char		*option;
  char		*value;
  int		is_enable;
  int		cp;

  cp = 1;
  if (arg[0] != '-')
    return (NULL);
  if (arg[1] == '-')
    cp = 2;
  if (((int)sm_len(arg)) <= cp)
    return (NULL);
  option = sm_splithead(&arg[cp], '=');
  value = sm_splittail(&arg[cp], '=');
  is_enable = (sm_egal(value, "no") || sm_egal(value, "unable")) ? 0 : 1;
  return (new_opt(option, is_enable, value));
}

t_list		*system_st_initopts(t_list *args)
{
  t_list	*opts;
  t_elem	*tmp;

  opts = new_list();
  args->rewind(args);
  while ((tmp = args->next(args)))
    opts->push(opts,
	_wrap(st_getopt((char*)tmp->mem), sizeof(t_opt)));
  return (opts);
}

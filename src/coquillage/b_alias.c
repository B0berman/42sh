/*
** b_alias.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. mai 24 01:31:59 2015 Antoine Favarel
** Last update dim. mai 24 21:48:57 2015 Antoine Favarel
*/

#include	"coquillage.h"
#include	"neptune/strmut.h"

static int	st_alias(t_system *sys, char *key, char *value)
{
  t_elem	*elem;
  t_opt		*opt;

  sys->opts->rewind(sys->opts);
  while ((elem = sys->opts->next(sys->opts)))
    if ((opt = (t_opt*)elem->mem) && sm_egal(opt->option, key))
      opt->value = value;
  return (0);
}

int		b_alias(t_system *sys, t_execute *alias)
{
  char		*key;
  char		*value;
  t_opt		*opt;

  if (alias->params->length != 2)
  {
    sys->print(sys, "alias [KEY] [VALUE]\n");
    return (1);
  }
  key = (char*)alias->params->at(alias->params, 0)->mem;
  value = (char*)alias->params->at(alias->params, 1)->mem;
  if (sys->isenable(sys, key))
    return (st_alias(sys, key, value));
  opt = new_opt(key, 1, value);
  sys->opts->push(sys->opts, _wrap(opt, sizeof(opt)));
  return (0);
}

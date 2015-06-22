/*
** shell_prompt.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 11:40:33 2015 Antoine Favarel
** Last update dim. mai 24 15:04:54 2015 Antoine Favarel
*/

#include	"coquillage.h"
#include	"neptune/strmut.h"

static void	st_act(t_system *sys, char *str)
{
  if (!str)
    return ;
  if (sm_egal(str, "#b"))
    sys->print(sys, C_BLUE);
  else if (sm_egal(str, "#r"))
    sys->print(sys, C_RED);
  else if (sm_egal(str, "#g"))
    sys->print(sys, C_GREEN);
  else if (sm_egal(str, "#e"))
    sys->print(sys, C_END);
  else if (sm_egal(str, "#s"))
    sys->print(sys, " ");
  else if (str[0] == '#')
    sys->print(sys, sys->getenv(sys, &str[1]));
  else
    sys->print(sys, str);
}

static void	st_printprompt(t_system *sys, char *fmstr)
{
  t_list	*list;
  t_elem	*tmp;

  list = sm_mulsplit(fmstr, " \t");
  list->rewind(list);
  while ((tmp = list->next(list)))
    st_act(sys, (char*)tmp->mem);
}

int		shell_prompt(t_system *system, char *fmstr)
{
  if (!fmstr)
    st_printprompt(system, "#b coquillage #e >");
  else
    st_printprompt(system, fmstr);
  return (0);
}

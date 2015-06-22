/*
** c_builtin.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 22:14:16 2015 Antoine Favarel
** Last update dim. mai 24 01:49:46 2015 Antoine Favarel
*/

#include	"coquillage.h"
#include	"neptune/strmut.h"

int		c_builtin(t_system *sys, t_execute *e)
{
  if (sm_egal(e->label, "cd"))
    return (b_cd(sys, e));
  else if (sm_egal(e->label, "echo"))
    return (b_echo(sys, e));
  else if (sm_egal(e->label, "env"))
    return (b_env(sys, e));
  else if (sm_egal(e->label, "setenv"))
    return (b_setenv(sys, e));
  else if (sm_egal(e->label, "setfmstr"))
    return (b_setfmstr(sys, e));
  else if (sm_egal(e->label, "alias"))
    return (b_alias(sys, e));
  else if (sm_egal(e->label, "exit"))
    return (42);
  else
    return (b_unsetenv(sys, e));
}

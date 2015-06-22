/*
** b_cd.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Pierre de Berny
** Login   <Moon@epitech.net>
** 
** Started on  Tue May 19 12:26:49 2015 Pierre de Berny
** Last update dim. mai 24 15:57:06 2015 Antoine Favarel
*/

#include	<unistd.h>

#include	"coquillage.h"
#include	"neptune/strmut.h"

static int	st_error(t_system *sys, char *error)
{
  sys->out->fd = 2;
  sys->print(sys, error);
  sys->out->fd = 1;
  return (1);
}

static int	cd_withargs(t_system *sys, t_elem *tmp)
{
  if (sm_egal("-", (char*)tmp->mem))
  {
    if (chdir(sys->getenv(sys, "OLDPWD")) == -1)
      return (st_error(sys, "Aucun fichier ou dossier de ce type.\n"));
    sys->setenv(sys, "OLDPWD", sys->getenv(sys, "PWD"));
    sys->setenv(sys, "PWD", getcwd(NULL, 0));
  }
  else
  {
    if (chdir((char*)tmp->mem) == -1)
      return (st_error(sys, "Aucun fichier ou dossier de ce type.\n"));
    sys->setenv(sys, "OLDPWD", sys->getenv(sys, "PWD"));
    sys->setenv(sys, "PWD", getcwd(NULL, 0));
  }
  return (0);
}

static int	cd_withoutarg(t_system *sys)
{
  if (chdir(sys->getenv(sys, "HOME")) == -1)
    return (st_error(sys, "Aucun fichier ou dossier de ce type.\n"));
  sys->setenv(sys, "OLDPWD", sys->getenv(sys, "PWD"));
  sys->setenv(sys, "PWD", sys->getenv(sys, "HOME"));
  return (0);
}

int		b_cd(t_system *sys, t_execute *cd)
{
  t_elem	*tmp;

  tmp = cd->params->first;
  if (tmp)
    return (cd_withargs(sys, tmp));
  else
    return (cd_withoutarg(sys));
}

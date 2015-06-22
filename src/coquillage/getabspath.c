/*
** getabspath.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 21:41:51 2015 Antoine Favarel
** Last update dim. mai 24 12:04:34 2015 Antoine Favarel
*/

#include	<unistd.h>

#include	"coquillage.h"
#include	"neptune/strmut.h"

static char	*st_compath(char *path, char *cmd)
{
  char		*n_p;

  n_p = sm_cat(path, "/");
  return (sm_cat(n_p, cmd));
}

static int	st_isdirect(char *cmd)
{
  if (cmd[0] == '/')
    return (1);
  else if (cmd[0] == '.')
    if (cmd[1] == '/')
      return (1);
  return (0);
}

char		*getabspath(t_system *sys, char *cmd)
{
  t_list	*paths;
  char		*ret;
  t_elem	*tmp;

  if (st_isdirect(cmd) && access(cmd, X_OK) == 0)
    return (cmd);
  else if (st_isdirect(cmd))
    return (NULL);
  if (sys->getenv(sys, "PATH") == NULL)
    return (NULL);
  paths = sm_split(sys->getenv(sys, "PATH"), ':');
  ret = NULL;
  paths->rewind(paths);
  if (paths->length == 0)
    sys->print(sys, "C'est la fin des harricots mec!\n");
  while ((tmp = paths->next(paths)))
    if (access(st_compath(tmp->mem, cmd), X_OK) == 0)
      ret = st_compath(tmp->mem, cmd);
  return (ret);
}

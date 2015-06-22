/*
** c_exec.c for coquillage in /home/zack/Epitech/PSU_2014_42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. mai 22 11:14:03 2015 Antoine Favarel
** Last update dim. mai 24 22:37:50 2015 Antoine Favarel
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	"coquillage.h"

static int	st_error(t_system *sys, char *error)
{
  sys->print(sys, "coquillage : %s : command not found.\n", error);
  return (1);
}

static int	st_exec(t_system *sys, t_execute *e)
{
  pid_t		pid;
  char		*path;
  int		ret;

  if ((path = getabspath(sys, e->label)) == NULL)
    return (st_error(sys, e->label));
  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
  {
    execve(path, getargs(e), sys->env(sys));
    exit(1);
  }
  waitpid(pid, &(ret), 0);
  return (WEXITSTATUS(ret));
}

int		c_exec(t_system *sys, t_execute *e)
{
  if (e->id == BUILTIN)
    return (c_builtin(sys, e));
  else
    return (st_exec(sys, e));
}

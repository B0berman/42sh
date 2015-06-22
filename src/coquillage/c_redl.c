/*
** c_redl.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. mai 22 13:49:51 2015 Antoine Favarel
** Last update ven. mai 22 14:20:37 2015 Antoine Favarel
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdlib.h>

#include	"coquillage.h"
#include	"neptune/strmut.h"

static void	st_close(int *fd, int pid, int pid2)
{
  close(fd[0]);
  close(fd[1]);
  waitpid(pid, NULL, 0);
  waitpid(pid2, NULL, 0);
}

static void	st_execpipe(t_system *sys, t_execute *e, int *fd)
{
  close(fd[1]);
  dup2(fd[0], 0);
  close(fd[0]);
  c_exec(sys, e);
  exit(1);
}

static void	st_execsend(t_system *sys, t_execute *e, int *fd)
{
  char		*str;
  t_io		*file;

  file = new_io(e->red_value);
  if (file->open(file) == EXIT_FAILURE)
    exit(1);
  close(fd[0]);
  dup2(fd[1], 1);
  close(fd[1]);
  while ((str = file->nextline(file, '\n')))
    sys->out->puts(sys->out, str, sm_len(str));
  exit(1);
}

int		c_redl(t_system *sys, t_execute *e)
{
  int		fd[2];
  int		pid;
  int		pid2;

  pid2 = -1;
  if (pipe(fd) == -1 || (pid = fork()) == -1)
    return (1);
  if (pid == 0)
    st_execpipe(sys, e, fd);
  else
  {
    if ((pid2 = fork()) == -1)
      return (1);
    if (pid2 == 0)
      st_execsend(sys, e, fd);
  }
  st_close(fd, pid, pid2);
  return (0);
}

/*
** c_pipe.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mer. mai 20 15:07:19 2015 Antoine Favarel
** Last update dim. mai 24 18:05:27 2015 Antoine Favarel
*/

#define		_XOPEN_SOURCE

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/wait.h>
#include	"coquillage.h"

static int	st_close(int *fd, int pid, int pid2)
{
  int		fox;

  close(fd[0]);
  close(fd[1]);
  waitpid(pid, &fox, 0);
  waitpid(pid2, NULL, 0);
  return (WEXITSTATUS(fox));
}

static void	st_execpipe(t_system *sys, t_node *n, int *fd, int r)
{
  close(fd[!r]);
  dup2(fd[r], r);
  close(fd[r]);
  exit(execute(sys, n));
}

int		c_pipe(t_system *sys, t_node *ast)
{
  int		fd[2];
  int		pid;
  int		pid2;

  pid2 = -1;
  if (pipe(fd) == -1 || (pid = fork()) == -1)
    return (1);
  if (pid == 0)
    st_execpipe(sys, ast->right, fd, 0);
  else
  {
    if ((pid2 = fork()) == -1)
      return (1);
    if (pid2 == 0)
      st_execpipe(sys, ast->left, fd, 1);
  }
  return (st_close(fd, pid, pid2));
}

/*
** c_redr.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. mai 22 11:24:32 2015 Antoine Favarel
** Last update dim. mai 24 22:30:26 2015 Antoine Favarel
*/

#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/wait.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<stdlib.h>

#include	"coquillage.h"

int		c_redr(t_system *sys, t_execute *e)
{
  int		fd;
  int		pid;
  int		fox;

  if ((pid = fork()) == -1)
    return (1);
  if (pid == 0)
  {
    if ((fd = open(e->red_value, O_WRONLY | O_TRUNC | O_CREAT,
	    S_IRUSR | S_IWUSR)) == -1)
      exit(1);
    dup2(fd, 1);
    exit(c_exec(sys, e));
  }
  waitpid(pid, &fox, 0);
  return (WEXITSTATUS(fox));
}

/*
** shell.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. mai 21 11:56:22 2015 Antoine Favarel
** Last update dim. mai 24 17:49:52 2015 Antoine Favarel
*/

#include	<unistd.h>
#include	<signal.h>

#include	"coquillage.h"
#include	"neptune/strmut.h"

static void	st_execrc(t_system *sys)
{
  t_io		*rc;
  char		*line;

  rc = new_io("res/.42sh.sh");
  rc->open(rc);
  while ((line = rc->nextline(rc, '\n')))
    shell_string(sys, line);
  rc->close(rc);
  delete_io(rc);
}

static void	st_signalint(int x)
{
  signal(SIGINT, st_signalint);
}

int		shell(int argc, char **argv, char **env)
{
  t_system	*sys;
  char		*str;
  int		ret;

  sys = new_system(argc, argv, env);
  sys->opts = new_list();
  sys->setenv(sys, "FMSTR", "#b coquillage #e");
  ret = 0;
  if (argc == 3 && sm_egal(argv[1], "-c"))
    return (shell_string(sys, argv[2]));
  st_execrc(sys);
  signal(SIGINT, st_signalint);
  while (ret != 42)
  {
    shell_prompt(sys, sys->getenv(sys, "FMSTR"));
    str = sys->in->nextline(sys->in, '\n');
    if (str)
      ret = shell_string(sys, str);
    else
      sys->print(sys, "\n");
  }
  return (ret);
}

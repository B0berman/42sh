/*
** init_system.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:12:40 2015 Antoine Favarel
** Last update dim. avril 26 18:26:35 2015 Antoine Favarel
*/

#include	"neptune/system.h"

static void	init_system_methods(t_system *system)
{
  system->isenable = &(system_isenable);
  system->getopt = &(system_getopt);
  system->env = &(system_env);
  system->setenv = &(system_setenv);
  system->unsetenv = &(system_unsetenv);
  system->getenv = &(system_getenv);
  system->print = &(system_print);
}

static void	init_system_values(t_system *s, int c, char **v, char **e)
{
  s->args = system_st_initargs(c, v);
  s->env_list = system_st_initenv_list(e);
  s->opts = system_st_initopts(s->args);
  s->in = new_io("system/stdin");
  s->in->fd = 0;
  s->out = new_io("system/stdout");
  s->out->fd = 1;
  s->err = new_io("system/stderr");
  s->err->fd = 2;
}

void		init_system(t_system *s, int ac, char **av, char **env)
{
  if (s)
  {
    init_system_methods(s);
    init_system_values(s, ac, av, env);
  }
}

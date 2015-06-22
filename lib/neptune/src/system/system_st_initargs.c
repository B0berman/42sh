/*
** system_st_initargs.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 18:38:47 2015 Antoine Favarel
** Last update dim. avril 26 18:42:56 2015 Antoine Favarel
*/

#include	"neptune/system.h"
#include	"neptune/strmut.h"

t_list		*system_st_initargs(int argc, char **argv)
{
  t_list	*args;
  int		i;

  i = -1;
  args = new_list();
  while (++i < argc)
    args->push(args, _mush(argv[i], sm_len(argv[i])));
  return (args);
}

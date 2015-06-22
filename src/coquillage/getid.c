/*
** getid.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon May 18 16:57:19 2015 walbec_h
** Last update dim. mai 24 01:29:24 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"neptune/strmut.h"
#include	"coquillage.h"

static int	getbuiltin(char *value)
{
  if (sm_egal(value, "echo")
      || sm_egal(value, "cd")
      || sm_egal(value, "setenv")
      || sm_egal(value, "setfmstr")
      || sm_egal(value, "unsetenv")
      || sm_egal(value, "env")
      || sm_egal(value, "alias")
      || sm_egal(value, "exit"))
    return (1);
  return (0);
}

t_id		getid(char *value)
{
  t_id		id;

  if (sm_egal(value, "&&"))
    id = AND;
  else if (sm_egal(value, "||"))
    id = OR;
  else if (sm_egal(value, "|"))
    id = PIPE;
  else if (sm_egal(value, "<<"))
    id = D_REDL;
  else if (sm_egal(value, "<"))
    id = REDL;
  else if (sm_egal(value, ">>"))
    id = D_REDR;
  else if (sm_egal(value, ">"))
    id = REDR;
  else if (sm_egal(value, ";"))
    id = SEMICOLON;
  else if (getbuiltin(value))
    id = BUILTIN;
  else
    id = CMD_ARG;
  return (id);
}

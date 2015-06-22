/*
** c_norm.c for coquillage in /home/zack/Epitech/PSU_2014_42sh/src/coquillage
** 
** Made by Antoine Meuniez
** Login   <meuniez_k@epitech.net>
** 
** Started on  jeu. mai 21 11:37:37 2015 Antoine Meuniez
** Last update dim. mai 24 22:36:18 2015 Antoine Favarel
*/

#include	<unistd.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	"coquillage.h"

int		c_norm(t_system *sys, t_execute *e)
{
  if (!e->is_redpresent)
    return (c_exec(sys, e));
  else if (e->redir == D_REDL)
    return (c_dredl(sys, e));
  else if (e->redir == D_REDR)
    return (c_dredr(sys, e));
  else if (e->redir == REDL)
    return (c_redl(sys, e));
  else if (e->redir == REDR)
    return (c_redr(sys, e));
  else
    return (1);
}

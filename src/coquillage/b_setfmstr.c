/*
** b_setfmstr.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Pierre de Berny
** Login   <Moon@epitech.net>
** 
** Started on  Thu May 21 15:47:42 2015 Pierre de Berny
** Last update dim. mai 24 17:50:32 2015 Antoine Favarel
*/

#include	"coquillage.h"

int		b_setfmstr(t_system *sys, t_execute *setfmstr)
{
  if (setfmstr->params->length == 1)
    {
      sys->setenv(sys, "FMSTR", (char*)setfmstr->params->first->mem);
      return (0);
    }
  else
    return (shell_string(sys, "cat res/fmstr.help"));
}

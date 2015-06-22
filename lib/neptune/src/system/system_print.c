/*
** system_print.c for system in /home/zack/Projects/neptune_architecte/src/system
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 21:26:25 2015 Antoine Favarel
** Last update mer. avril 29 14:34:35 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	<stdarg.h>
#include	"neptune/system.h"
#include	"neptune/strmut.h"

int		system_print(t_system *this, char *str, ...)
{
  va_list	ap;
  int		i;
  char		*t;

  va_start(ap, str);
  i = -1;
  if (!this || !str)
    return (0);
  while (str[++i])
    if (str[i] == '%')
    {
      i++;
      if (str[i] == '%')
	this->out->puts(this->out, "%", 1);
      else if ((str[i] == 'd' || str[i] == 'i')
	  && (t = sm_fromint(va_arg(ap, int), "0123456789")))
	this->out->puts(this->out, t, sm_len(t));
      else if (str[i] == 's' && (t = va_arg(ap, char*)))
	this->out->puts(this->out, t, sm_len(t));
    }
    else
      this->out->puts(this->out, &str[i], 1);
  va_end(ap);
  return (1);
}

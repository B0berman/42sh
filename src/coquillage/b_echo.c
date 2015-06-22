/*
** b_echo.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Pierre de Berny
** Login   <Moon@epitech.net>
** 
** Started on  Thu May 21 12:09:59 2015 Pierre de Berny
** Last update dim. mai 24 16:57:25 2015 Antoine Favarel
*/

#include	"coquillage.h"
#include	"neptune/strmut.h"

static char	st_getchar(char c)
{
  if (c == 'a')
    return ('\a');
  else if (c == 'b')
    return ('\b');
  else if (c == 'e')
    return ('\033');
  else if (c == 'f')
    return ('\f');
  else if (c == 'n')
    return ('\n');
  else if (c == 'r')
    return ('\r');
  else if (c == 't')
    return ('\t');
  else if (c == 'v')
    return ('\v');
  else
    return (c);
}

static void	st_print(t_system *sys, int e, char *str)
{
  int		i;
  char		c;

  i = -1;
  while (str[++i])
    if (str[i] == '\\' && e)
    {
      c = st_getchar(str[++i]);
      sys->out->puts(sys->out, &c, 1);
    }
    else
      sys->out->puts(sys->out, &str[i], 1);
}

int		b_echo(t_system *sys, t_execute *echo)
{
  t_elem	*tmp;
  int		e;
  int		n;

  e = 0;
  n = 0;
  echo->params->rewind(echo->params);
  while ((tmp = echo->params->next(echo->params)))
  {
    if (sm_egal((char*)tmp->mem, "-n"))
      n = 1;
    else if (sm_egal((char*)tmp->mem, "-e"))
      e = 1;
    else if (sm_egal((char*)tmp->mem, "-E"))
      e = 0;
    else
      st_print(sys, e, (char*)tmp->mem);
    if (tmp->next)
      sys->print(sys, " ");
  }
  if (!n)
    sys->print(sys, "\n");
  return (0);
}

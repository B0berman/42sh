/*
** sm_replacec.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mer. mars 04 10:16:18 2015 Antoine Favarel
** Last update jeu. avril 23 17:11:20 2015 Antoine Favarel
*/

#include	"strmut.h"

static void	st_replacec(char *str, char cible, char r)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] == cible)
      str[i] = r;
}

void		sm_replacec(char *str, char cible, char r)
{
  if (str)
    st_replacec(str, cible, r);
}

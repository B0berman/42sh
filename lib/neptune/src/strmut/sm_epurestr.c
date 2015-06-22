/*
** sm_epurestr.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mer. mars 04 09:58:50 2015 Antoine Favarel
** Last update jeu. avril 23 17:02:51 2015 Antoine Favarel
*/

#include	"strmut.h"

static int	st_calcs(char *str, char c)
{
  int		i;
  int		len;

  i = -1;
  len = 0;
  while (str[++i] && str[i] == c);
  i--;
  while (str[++i])
    if (str[i] != c || (str[i] == c && str[i + 1] && str[i + 1] != c))
      len++;
  return (len);
}

char		*sm_epurestr(char *str, char c)
{
  char		*n_str;
  int		i;
  int		j;

  if (!str)
    return (NULL);
  if (!(n_str = malloc(sizeof(char) * (st_calcs(str, c) + 1))))
    return (NULL);
  i = -1;
  j = 0;
  while (str[++i] && str[i] == c);
  i--;
  while (str[++i])
    if (str[i] != c || (str[i] == c && str[i + 1] && str[i + 1] != c))
    {
      n_str[j] = str[i];
      j++;
    }
  n_str[j] = '\0';
  return (n_str);
}

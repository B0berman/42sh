/*
** sm_fromint.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 22:06:38 2015 Antoine Favarel
** Last update dim. avril 26 22:19:30 2015 Antoine Favarel
*/

#include	"neptune/strmut.h"

char		*sm_fromint(int nb, char *base)
{
  char		*str;
  int		i;
  int		len;
  int		size;

  len = sm_len(base);
  size = sm_getdigits(nb, len);
  if (!(str = malloc(size + 1)))
    return (NULL);
  i = 0;
  len = sm_len(base);
  while (nb / len % len > 0)
    str[size - i - 1] = base[nb % len];
  str[size] = '\0';
  return (str);
}

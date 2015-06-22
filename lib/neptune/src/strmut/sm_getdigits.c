/*
** sm_getdigits.c for strmut in /home/zack/Projects/neptune_architecte/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 21:51:53 2015 Antoine Favarel
** Last update dim. avril 26 22:05:20 2015 Antoine Favarel
*/

#include	"neptune/strmut.h"

int		sm_getdigits(int nb, int base)
{
  int		digits;

  digits = 0;
  while (nb > 0)
  {
    digits++;
    nb /= 10;
  }
  return (digits);
}

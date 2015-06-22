/*
** sm_lento.c for strmut in /home/zack/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. mai 23 20:35:12 2015 Antoine Favarel
** Last update sam. mai 23 20:36:00 2015 Antoine Favarel
*/

#include	"neptune/strmut.h"

size_t		sm_lento(char *str, char to)
{
  size_t	len;

  len = 0;
  while (str[len] && str[len] != to)
    len++;
  return (len);
}

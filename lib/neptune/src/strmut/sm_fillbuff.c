/*
** sm_fillbuff.c for strmut in /home/zack/neptune/src/strmut
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. févr. 24 17:53:48 2015 Antoine Favarel
** Last update dim. mai 24 13:07:17 2015 Antoine Favarel
*/

#include	"strmut.h"

void		sm_fillbuff(char *buff, char *src, size_t len_buff)
{
  size_t	i;

  i = 0;
  while (src[i] && i < len_buff)
  {
    buff[i] = src[i];
    i++;
  }
  while (i < len_buff)
  {
    buff[i] = '\0';
    i++;
  }
}

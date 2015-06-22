/*
** new_io.c for io in /home/zack/Projects/neptune_architecte/src/io
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 02:39:11 2015 Antoine Favarel
** Last update dim. avril 19 17:03:46 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"io.h"

t_io		*new_io(char *src)
{
  t_io		*io;

  if (!(io = malloc(sizeof(t_io))))
    return (NULL);
  init_io(io, src);
  return (io);
}

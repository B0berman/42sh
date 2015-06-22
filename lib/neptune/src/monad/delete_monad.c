/*
** delete_monad.c for monad in /home/zack/Projects/neptune_architecte/src/monad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 18:17:32 2015 Antoine Favarel
** Last update lun. avril 20 18:18:13 2015 Antoine Favarel
*/

#include	<stdlib.h>
#include	"monad.h"

void		delete_monad(t_monad *monad)
{
  uninit_monad(monad);
  if (monad)
    free(monad);
}

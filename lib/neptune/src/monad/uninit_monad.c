/*
** uninit_monad.c for monad in /home/zack/Projects/neptune_architecte/src/monad
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 18:18:30 2015 Antoine Favarel
** Last update lun. avril 20 18:19:19 2015 Antoine Favarel
*/

#include	"monad.h"

void		uninit_monad(t_monad *monad)
{
  if (monad)
    monad->stop(monad);
}

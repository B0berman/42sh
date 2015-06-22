/*
** tokenize.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by walbec_h
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue May 19 14:03:18 2015 walbec_h
** Last update dim. mai 24 22:01:54 2015 Antoine Favarel
*/

#include	"neptune/strmut.h"
#include	"coquillage.h"

static void	st_fill(t_list *r_words, t_system *sys, char *key)
{
  t_list	*words;
  t_elem	*tmp;

  if (!(words = splitcmd(sys->getopt(sys, key))))
    return ;
  words->rewind(words);
  while ((tmp = words->next(words)))
    r_words->push(r_words, _wrap(tmp->mem, tmp->size_of_mem));
}

static t_list	*st_trait(t_list *words, t_system *sys)
{
  t_list	*r_words;
  t_elem	*tmp;
  char		*prev_tmp;

  r_words = new_list();
  words->rewind(words);
  prev_tmp = NULL;
  while ((tmp = words->next(words)))
  {
    if (sys->isenable(sys, (char*)tmp->mem)
	&& (prev_tmp == NULL
	  || getid(prev_tmp) == PIPE || getid(prev_tmp) == AND
	  || getid(prev_tmp) == OR || getid(prev_tmp) == SEMICOLON))
      st_fill(r_words, sys, (char*)tmp->mem);
    else
      r_words->push(r_words, _wrap(tmp->mem, tmp->size_of_mem));
    prev_tmp = (char*)tmp->mem;
  }
  return (r_words);
}

t_list		*tokenize(char *str, t_system *sys)
{
  t_list	*tokenize;
  t_list	*words;
  t_elem	*elem;
  t_token	*token;

  tokenize = new_list();
  str = sm_epurestr(str, ' ');
  str = sm_epurestr(str, '\t');
  if (!(words = splitcmd(str)))
    return (NULL);
  words = st_trait(words, sys);
  words->rewind(words);
  while ((elem = words->next(words)))
    {
      token = gettoken(elem->mem);
      tokenize->push(tokenize, _wrap(token, sizeof(t_token)));
    }
  return (tokenize);
}

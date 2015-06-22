/*
** splitcmd.c for coquillage in /home/zack/Epitech/42sh/src/coquillage
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  sam. mai 23 19:00:53 2015 Antoine Favarel
** Last update dim. mai 24 20:33:46 2015 Antoine Favarel
*/

#include	<glob.h>

#include	"coquillage.h"
#include	"neptune/strmut.h"

static int	verifp(char *string)
{
  int		i;
  int		p;

  i = -1;
  p = 0;
  while (string[++i])
    if (string[i] == '"')
      p++;
  return (!(p % 2));
}

static void	st_globbing(char *str, t_list *w)
{
  glob_t	globbuf;
  int		i;

  i = -1;
  if (!(sm_is_strcontainc(str, '*')
      || sm_is_strcontainc(str, '~')))
  {
    w->push(w, _wrap(str, sm_len(str)));
    return ;
  }
  if (glob(str, GLOB_TILDE, NULL, &globbuf) == GLOB_NOMATCH)
  {
    w->push(w, _wrap(str, sm_len(str)));
    return ;
  }
  while (globbuf.gl_pathv[++i])
    w->push(w, _wrap(globbuf.gl_pathv[i],
	  sm_len(globbuf.gl_pathv[i])));
}

static void	st_cutsep(char *str, int i, int *j, t_list *w)
{
  char		*n_str;

  n_str = sm_dupn(&str[*j], i - *j);
  if (sm_len(n_str) != 0)
    st_globbing(n_str, w);
  *j = i + 1;
}

static void	st_cutgim(char *str, int *i, int *j, t_list *w)
{
  char		*n_str;

  if (*i != *j)
  {
    n_str = sm_dupn(&str[*j], *i - *j);
    if (!(sm_len(n_str) == 1
	  && sm_is_strcontainc(C_SEP, n_str[0])))
      st_globbing(n_str, w);
    *j = *i;
  }
  n_str = sm_dupn(&str[*i + 1], sm_lento(&str[*i + 1], '"'));
  w->push(w, _wrap(n_str, sm_len(n_str)));
  *i += sm_len(n_str) + 1;
  *j = *i + 1;
}

t_list		*splitcmd(char *str)
{
  t_list	*words;
  int		i;
  int		j;

  if (!verifp(str))
    return (NULL);
  i = -1;
  j = 0;
  words = new_list();
  while (str[++i])
  {
    if (str[i] == '"')
      st_cutgim(str, &i, &j, words);
    else if (sm_is_strcontainc(C_SEP, str[i]))
      st_cutsep(str, i, &j, words);
  }
  if (j != i)
    st_globbing(&str[j], words);
  return (words);
}

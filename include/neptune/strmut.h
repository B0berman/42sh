/*
** strmut.h for neptune in /home/zack/Epitech/42sh/include/neptune
** 
** Made by Antoine Favarel
** Login   <antoine.favarel@epitech.net>
** 
** Started on  Fri Nov 28 04:06:46 2014 Antoine Favarel
** Last update dim. mai 24 22:11:44 2015 Antoine Favarel
*/

#ifndef		STRMUT_H_
# define	STRMUT_H_

# include	<stdlib.h>
# include	<limits.h>

# include	"neptune/list.h"

void		sm_copy(char *dest, char *src);
void		sm_fillbuff(char *buff, char *src, size_t len_buff);
void		sm_replacec(char *str, char cible, char r);
char		*sm_fromint(int nb, char *base);
char		*sm_epurestr(char *str, char c);
char		*sm_dupc(char c);
char		*sm_dupn(char *str, size_t len);
char		*sm_dup(char *str);
char		*sm_cat(char *s1, char *s2);
char		*sm_splithead(char *str, char spliter);
char		*sm_splittail(char *str, char spliter);
t_list		*sm_split(char *str, char spliter);
t_list		*sm_mulsplit(char *str, char *spliters);
int		sm_is_strcontainc(char *str, char c);
int		sm_egal(char *s1, char *s2);
int		sm_cmp(char *s1, char *s2);
int		sm_getint(char *str);
int		*sm_getmint(char *str);
int		sm_getdigits(int nombre, int base);
unsigned int	sm_getuint(char *str);
unsigned int	*sm_getmuint(char *str);
long		sm_getlong(char *str);
long		*sm_getmlong(char *str);
unsigned long	sm_getulong(char *str);
unsigned long	*sm_getmulong(char *str);
size_t		sm_len(char *str);
size_t		sm_lento(char *str, char to);

#endif		/* !STRMUT_H_ */

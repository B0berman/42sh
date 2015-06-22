/*
** system.h for neptune in /home/zack/Projects/neptune_architecte/include/neptune
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 26 16:59:27 2015 Antoine Favarel
** Last update dim. avril 26 18:24:33 2015 Antoine Favarel
*/

#ifndef		NEP_SYSTEM_H_
# define	NEP_SYSTEM_H_

# include	"neptune/list.h"
# include	"neptune/io.h"

typedef	struct	s_opt
{
  char		*option;
  int		is_enable;
  char		*value;
}		t_opt;

typedef	struct	s_enventry
{
  char		*key;
  char		*value;
}		t_enventry;

typedef	struct	s_system
{
  t_list	*args;
  t_list	*env_list;
  t_list	*opts;
  t_io		*in;
  t_io		*out;
  t_io		*err;
  int		(*isenable)(struct s_system *, char *option);
  char		*(*getopt)(struct s_system *, char *option);
  char		**(*env)(struct s_system *);
  void		(*setenv)(struct s_system *, char *key, char *value);
  void		(*unsetenv)(struct s_system *, char *key);
  char		*(*getenv)(struct s_system *, char *key);
  int		(*print)(struct s_system *, char *str, ...);
}		t_system;

/* data opt */
t_opt		*new_opt(char *option, int is_enable, char *value);
/* data enventry */
t_enventry	*new_enventry(char *key, char *value);
/* class system */
t_system	*new_system(int argc, char **argv, char **env);
void		init_system(t_system *s, int ac, char **av, char **env);
int		system_isenable(t_system *this, char *option);
char		*system_getopt(t_system *this, char *option);
char		**system_env(t_system *this);
void		system_setenv(t_system *this, char *key, char *value);
void		system_unsetenv(t_system *this, char *key);
char		*system_getenv(t_system *this, char *key);
int		system_print(t_system *this, char *str, ...);
void		uninit_system(t_system *s);
void		delete_system(t_system *s);
/* static system */
t_list		*system_st_initargs(int argc, char **argv);
t_list		*system_st_initenv_list(char **env);
t_list		*system_st_initopts(t_list *args);

#endif		/* !NEP_SYSTEM_H_ */


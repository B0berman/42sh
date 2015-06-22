/*
** coquillage.h for include in /home/zack/Epitech/42sh/include
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. mai 18 10:28:37 2015 Antoine Favarel
** Last update dim. mai 24 21:48:33 2015 Antoine Favarel
*/

#ifndef		COQUILLAGE_H_
# define	COQUILLAGE_H_

# define	C_SEP		" \t"
# define	C_TOK		'"'
# define	C_RED		"\033[0;31m"
# define	C_BLUE		"\033[0;34m"
# define	C_GREEN		"\033[0;32m"
# define	C_END		"\033[0m"

# include	"neptune/list.h"
# include	"neptune/system.h"

typedef	enum	e_id
{
  BUILTIN,
  CMD_ARG,
  D_REDL,
  D_REDR,
  REDL,
  REDR,
  PIPE,
  OR,
  AND,
  SEMICOLON
}		t_id;

typedef	struct	s_token
{
  t_id		id;
  char		*value;
}		t_token;

typedef	struct	s_execute
{
  t_id		id;
  char		*label;
  t_list	*params;
  char		is_redpresent;
  t_id		redir;
  char		*red_value;
}		t_execute;

typedef	struct	s_node
{
  t_execute	*execute;
  struct s_node	*left;
  struct s_node	*right;
}		t_node;

t_token		*new_token(t_id id, char *value);
t_execute	*new_execute(t_id id, char *label);
t_node		*new_node(t_execute *execute);
void		free_token(t_token *token);
void		free_execute(t_execute *execute);
void		free_node(t_node *node);
void		free_stack(t_list *stack);
void		free_tree(t_node *tree);
char		*getabspath(t_system *sys, char *cmd);
char		**getargs(t_execute *e);
t_id		getid(char *value);
t_token		*gettoken(char *value);
t_list		*splitcmd(char *string);
t_list		*tokenize(char *string, t_system *sys);
t_execute	*getexecute(t_list *stack);
t_list		*lexer(t_list *stack);
t_node		*tree(t_list *stack);
t_node		*translate(char *string, t_system *sys);
int		execute(t_system *sys, t_node *ast);
int		c_builtin(t_system *sys, t_execute *e);
int		c_exec(t_system *sys, t_execute *e);
int		c_norm(t_system *sys, t_execute *e);
int		c_dredl(t_system *sys, t_execute *e);
int		c_dredr(t_system *sys, t_execute *e);
int		c_redl(t_system *sys, t_execute *e);
int		c_redr(t_system *sys, t_execute *e);
int		c_pipe(t_system *sys, t_node *ast);
int		c_or(t_system *sys, t_node *ast);
int		c_and(t_system *sys, t_node *ast);
int		c_semicolon(t_system *sys, t_node *ast);
int		b_echo(t_system *sys, t_execute *echo);
int		b_cd(t_system *sys, t_execute *cd);
int		b_setenv(t_system *sys, t_execute *setenv);
int		b_unsetenv(t_system *sys, t_execute *unsetenv);
int		b_env(t_system *sys, t_execute *env);
int		b_alias(t_system *sys, t_execute *alias);
int		b_setfmstr(t_system *sys, t_execute *setfmstr);
int		shell_string(t_system *system, char *value);
int		shell_prompt(t_system *system, char *fmstr);
int		shell(int ac, char **av, char **env);

#endif		/* !COQUILLAGE_H_ */


/*
** dispatcher.h for clust in /home/zack/Projects/neptune_architecte/include/neptune/clust
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mar. avril 21 13:59:30 2015 Antoine Favarel
** Last update sam. avril 25 13:49:19 2015 Antoine Favarel
*/

#ifndef			NEP_C_DISPATCHER_H_
# define		NEP_C_DISPATCHER_H_

# include		"neptune/server.h"
# include		"neptune/clust/protocole.h"

typedef	struct		s_d_arg
{
  void			*server;
  void			*socket;
  void			*l_orders;
}			t_d_arg;

typedef	struct		s_dispatcher
{
  /*			< t_server*/
  char			*src;
  int			fd;
  char			*buffer;
  size_t		buffsize;
  int			is_assync;
  pthread_mutex_t	mutex;
  pthread_mutexattr_t	attr;
  int			(*open)(struct s_dispatcher *);
  int			(*puts)(struct s_dispatcher *, char *b, size_t s);
  int			(*gets)(struct s_dispatcher *, char *b, size_t s);
  char			*(*nextline)(struct s_dispatcher *, char separator);
  int			(*close)(struct s_dispatcher *);
  void			(*gst_close)(struct s_dispatcher *);
  void			(*gst_recv)(struct s_dispatcher *, char *b, size_t s);
  void			(*assync)(struct s_dispatcher *, int on_off);
  void			(*lock)(struct s_dispatcher *);
  void			(*unlock)(struct s_dispatcher *);
  int			port;
  pthread_t		main;
  t_list		*clients;
  void			*(*gst_connection)(void *arg);
  void			*(*gst_disconnection)(void *arg);
  /*			< new*/
  t_list		*data;
  t_list		*orders;
  t_list		*responds;
  void			(*update)(struct s_dispatcher *);
}			t_dispatcher;

t_dispatcher		*new_dispatcher(char *addr, int port);
void			init_dispatcher(t_dispatcher *, char *ad, int port);
void			*dispatcher_connection(void *arg);
int			dispatcher_open(t_dispatcher *this);
void			dispatcher_update(t_dispatcher *this);
void			uninit_dispatcher(t_dispatcher *dispatcher);
void			delete_dispatcher(t_dispatcher *dispatcher);

#endif			/* !NEP_C_DISPATCHER_H_ */


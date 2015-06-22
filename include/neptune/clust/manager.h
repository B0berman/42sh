/*
** manager.h for clust in /home/zack/Projects/neptune_architecte/include/neptune/clust
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 19:24:24 2015 Antoine Favarel
** Last update mer. avril 29 15:12:18 2015 Antoine Favarel
*/

#ifndef			NEP_C_MANAGER_H_
# define		NEP_C_MANAGER_H_

# include		"neptune/socket.h"
# include		"neptune/monad.h"
# include		"neptune/clust/protocole.h"

typedef	t_data		*(*t_ptr_actor)(t_monad *this, t_data *object);

typedef	struct		s_manager
{
  /*			< t_socket*/
  char			*src;
  int			fd;
  char			*buffer;
  size_t		buffsize;
  int			is_assync;
  pthread_mutex_t	mutex;
  pthread_mutexattr_t	attr;
  int			(*open)(struct s_manager *);
  int			(*puts)(struct s_manager *, char *buffer, size_t size);
  int			(*gets)(struct s_manager *, char *buffer, size_t size);
  char			*(*nextline)(struct s_manager *, char separator);
  int			(*close)(struct s_manager *);
  void			(*gst_close)(struct s_manager *);
  void			(*gst_recv)(struct s_manager *, char *bf, size_t size);
  void			(*assync)(struct s_manager *, int on_off);
  void			(*lock)(struct s_manager *);
  void			(*unlock)(struct s_manager *);
  int			port;
  pthread_t		main;
  /*			new*/
  t_list		*monads;
  t_list		*in;
  t_list		*out;
  t_list		*data;
  int			coexiam;
  t_ptr_actor		actor;
  pthread_cond_t	is_akn;
  void			(*update)(struct s_manager *, t_list *data);
}			t_manager;

t_manager		*new_manager(char *src, int port, int coexiam);
void			init_manager(t_manager *, char *ad, int p, int c);
void			*manager_main(void *this);
int			manager_open(t_manager *this);
void			manager_update(t_manager *this, t_list *data);
void			manager_unicorning(t_manager *this);
void			uninit_manager(t_manager *manager);
void			delete_manager(t_manager *manager);

#endif			/* !NEP_C_MANAGER_H_ */


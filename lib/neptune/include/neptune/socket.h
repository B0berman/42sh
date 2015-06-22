/*
** socket.h for neptune in /home/zack/Projects/neptune_architecte/include/neptune
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  dim. avril 19 18:19:48 2015 Antoine Favarel
** Last update mer. avril 29 13:48:51 2015 Antoine Favarel
*/

#ifndef			NEP_SOCKET_H_
# define		NEP_SOCKET_H_

# include		"neptune/io.h"

typedef	struct		s_socket
{
  /*			< t_io*/
  char			*src;
  int			fd;
  char			*buffer;
  size_t		buffsize;
  int			is_assync;
  pthread_mutex_t	mutex;
  pthread_mutexattr_t	attr;
  int			(*open)(struct s_socket *);
  int			(*puts)(struct s_socket *, char *buffer, size_t size);
  int			(*gets)(struct s_socket *, char *buffer, size_t size);
  char			*(*nextline)(struct s_socket *, char separator);
  int			(*close)(struct s_socket *);
  void			(*gst_close)(struct s_socket *);
  void			(*gst_recv)(struct s_socket *, char *buf, size_t size);
  void			(*assync)(struct s_socket *, int on_off);
  void			(*lock)(struct s_socket *);
  void			(*unlock)(struct s_socket *);
  /*			new*/
  int			port;
  pthread_t		main;
}			t_socket;

t_socket		*new_socket(char *addr, int port);
void			init_socket(t_socket *, char *ad, int port);
void			*socket_main(void *this);
int			socket_open(t_socket *this);
void			uninit_socket(t_socket *socket);
void			delete_socket(t_socket *socket);

#endif			/* !NEP_SOCKET_H_ */


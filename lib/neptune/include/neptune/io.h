/*
** io.h for include in /home/zack/Projects/neptune_architecte/include
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  jeu. avril 16 11:32:16 2015 Antoine Favarel
** Last update ven. avril 24 23:50:37 2015 Antoine Favarel
*/

#ifndef			NEP_IO_H_
# define		NEP_IO_H_

# include		<sys/types.h>
# include		<pthread.h>

typedef	struct		s_io
{
  char			*src;
  int			fd;
  char			*buffer;
  size_t		buffsize;
  int			is_assync;
  pthread_mutex_t	mutex;
  pthread_mutexattr_t	attr;
  int			(*open)(struct s_io *);
  int			(*puts)(struct s_io *, char *buffer, size_t size);
  int			(*gets)(struct s_io *, char *buffer, size_t size);
  char			*(*nextline)(struct s_io *, char separator);
  int			(*close)(struct s_io *);
  void			(*gst_close)(struct s_io *);
  void			(*gst_recv)(struct s_io *, char *buffer, size_t size);
  void			(*assync)(struct s_io *, int on_off);
  void			(*lock)(struct s_io *);
  void			(*unlock)(struct s_io *);
}			t_io;

t_io			*new_io(char *src);
void			init_io(t_io *io, char *src);
int			io_open(t_io *this);
int			io_puts(t_io  *this, char *buffer, size_t size);
int			io_gets(t_io *this, char *buffer, size_t size);
char			*io_nextline(t_io *this, char separator);
int			io_close(t_io *this);
void			io_assync(t_io *this, int on_off);
void			io_lock(t_io *this);
void			io_unlock(t_io *this);
void			uninit_io(t_io *io);
void			delete_io(t_io *io);

#endif		/* !NEP_IO_H_ */


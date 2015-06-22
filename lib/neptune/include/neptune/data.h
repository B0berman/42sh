/*
** data.h for neptune in /home/zack/Projects/neptune_architecte/include/neptune
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 04:12:44 2015 Antoine Favarel
** Last update sam. avril 25 13:59:27 2015 Antoine Favarel
*/

#ifndef			NEP_DATA_H_
# define		NEP_DATA_H_

# include		<sys/types.h>
# include		<pthread.h>
# include		"neptune/io.h"

typedef	struct		s_data
{
  size_t		size_of_mem;
  int			magic_cmp;
  int			is_local;
  int			id;
  void			*mem;
  pthread_mutex_t	mutex;
  void			(*set_mem)(struct s_data *, void *mem, size_t size);
  void			(*set_dupmem)(struct s_data *, void *mem, size_t size);
  void			(*save)(struct s_data *, t_io *stream);
  int			(*load)(struct s_data *, t_io *stream);
  int			(*check)(struct s_data *);
  void			(*x)(struct s_data *, size_t i, void *b, size_t size);
  void			(*lock)(struct s_data *);
  void			(*unlock)(struct s_data *);
}			t_data;

t_data			*new_data();
void			init_data(t_data *data);
void			data_set_mem(t_data *this, void *mem, size_t size);
void			data_set_dupmem(t_data *this, void *mem, size_t size);
void			data_save(t_data *this, t_io *stream);
int			data_load(t_data *this, t_io *stream);
int			data_check(t_data *this);
void			data_x(t_data *this, size_t i, void *buf, size_t size);
void			data_lock(t_data *this);
void			data_unlock(t_data *this);
void			uninit_data(t_data *data);
void			delete_data(t_data *data);

#endif		/* !NEP_DATA_H_ */


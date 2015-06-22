/*
** monad.h for neptune in /home/zack/Projects/neptune_architecte/include/neptune
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  lun. avril 20 16:04:08 2015 Antoine Favarel
** Last update sam. avril 25 02:23:47 2015 Antoine Favarel
*/

#ifndef			NEP_MONAD_H_
# define		NEP_MONAD_H_

# include		"neptune/list.h"

typedef	struct		s_monad
{
  t_list		*queue_in;
  t_list		*queue_out;
  t_list		*data;
  pthread_t		main;
  t_data		*(*gst_actor)(struct s_monad *, t_data *object);
  void			(*start)(struct s_monad *);
  void			(*stop)(struct s_monad *);
  void			(*update)(struct s_monad *, t_list *data);
}			t_monad;

t_monad			*new_monad(t_list *queue_in, t_list *queue_out);
void			init_monad(t_monad *, t_list *q_in, t_list *q_out);
void			monad_start(t_monad *this);
void			monad_stop(t_monad *this);
void			monad_update(t_monad *this, t_list *data);
void			*monad_main(void *this);
void			uninit_monad(t_monad *monad);
void			delete_monad(t_monad *monad);

#endif			/* !NEP_MONAD_H_ */


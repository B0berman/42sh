/*
** list.h for neptune in /home/zack/Projects/neptune_architecte/include/neptune
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  ven. avril 17 04:09:25 2015 Antoine Favarel
** Last update sam. avril 25 16:56:05 2015 Antoine Favarel
*/

#ifndef			NEP_LIST_H_
# define		NEP_LIST_H_

# define		LIST_SET		0
# define		LIST_CUR		1
# define		LIST_END		2

# define		_wrap(mem, s)		new_init_static_elem(mem, s)
# define		_mush(mem, s)		new_init_dynamic_elem(mem, s)

# include		<pthread.h>
# include		"neptune/data.h"

/* t_elem extend of t_data */
typedef	struct		s_elem
{
  /*			< t_data*/
  size_t		size_of_mem;
  int			magic_cmp;
  int			is_local;
  int			id;
  void			*mem;
  pthread_mutex_t	mutex;
  void			(*set_mem)(struct s_elem *, void *mem, size_t size);
  void			(*set_dupmem)(struct s_elem *, void *mem, size_t size);
  void			(*save)(struct s_elem *, t_io *stream);
  int			(*load)(struct s_elem *, t_io *stream);
  int			(*check)(struct s_elem *);
  void			(*x)(struct s_elem *, size_t i, void *b, size_t size);
  void			(*lock)(struct s_elem *);
  void			(*unlock)(struct s_elem *);
  /*			new*/
  struct s_elem		*prev;
  struct s_elem		*next;
  struct s_elem		*(*dup)(struct s_elem *this);
}			t_elem;

typedef	struct		s_list
{
  t_elem		*first;
  t_elem		*last;
  t_elem		*cursor;
  size_t		length;
  pthread_mutex_t	mutex;
  pthread_mutexattr_t	attr;
  pthread_cond_t	is_fill;
  int			magic_cmp;
  t_elem		*(*at)(struct s_list *, size_t id);
  t_elem		*(*add_first)(struct s_list *, t_elem *elem);
  t_elem		*(*add_last)(struct s_list *, t_elem *elem);
  t_elem		*(*push)(struct s_list *list, t_elem *elem);
  t_elem		*(*pop)(struct s_list *list);
  t_elem		*(*popret)(struct s_list *list);
  t_elem		*(*get)(struct s_list *list, int id);
  void			(*seek)(struct s_list *, size_t id, char POS);
  void			(*rewind)(struct s_list *);
  t_elem		*(*next)(struct s_list *);
  t_elem		*(*prev)(struct s_list *);
  void			(*put)(struct s_list *, struct s_list *);
  int			(*remove)(struct s_list *, t_elem *elem);
  int			(*remove_at)(struct s_list *, size_t id);
  void			(*save)(struct s_list *, t_io *stream);
  int			(*load)(struct s_list *, t_io *stream);
  int			(*check)(struct s_list *);
  void			(*swap)(struct s_list *, t_elem *e1, t_elem *e2);
  void			(*swap_at)(struct s_list *, size_t id1, size_t id2);
  void			(*lock)(struct s_list *);
  void			(*unlock)(struct s_list *);
}			t_list;

/* t_elem */
t_elem			*new_elem(); /* M */
t_elem			*new_init_static_elem(void *mem, size_t size); /* M */
t_elem			*new_init_dynamic_elem(void *mem, size_t size); /* M */
void			init_elem(t_elem *elem);
t_elem			*elem_dup(t_elem *this); /* M */
void			uninit_elem(t_elem *elem);
void			delete_elem(t_elem *elem); /* M */
/* t_list */
t_list			*new_list(); /* M */
void			init_list(t_list *list);
t_elem			*list_at(t_list *this, size_t id); /* M */
t_elem			*list_add_first(t_list *this, t_elem *elem); /* M */
t_elem			*list_add_last(t_list *this, t_elem *elem); /* M */
t_elem			*list_push(t_list *this, t_elem *elem); /* M */
t_elem			*list_pop(t_list *this); /* M */
t_elem			*list_popret(t_list *this);
t_elem			*list_get(t_list *this, int id);
void			list_seek(t_list *this, size_t id, char pos); /* M */
void			list_rewind(t_list *this); /* M */
t_elem			*list_next(t_list *this); /* M */
t_elem			*list_prev(t_list *this); /* M */
void			list_put(t_list *this, t_list *src);
int			list_remove(t_list *this, t_elem *elem); /* W */
int			list_remove_at(t_list *this, size_t id); /* W */
void			list_save(t_list *this, t_io *stream); /* W */
int			list_load(t_list *this, t_io *stream); /* W */
int			list_check(t_list *this); /* W */
void			list_swap(t_list *this, t_elem *e1, t_elem *e2); /* W */
void			list_swap_at(t_list *this, size_t id1, size_t id2); /* W */
void			list_lock(t_list *this); /* M */
void			list_unlock(t_list *this); /* M */
void			uninit_list(t_list *list);
void			delete_list(t_list *list); /* M */

#endif		/* !NEP_LIST_H_*/


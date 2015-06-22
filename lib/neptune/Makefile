##
## Makefile for neptune in /home/zack/neptune
##
## Made by Antoine Favarel
## Login   <favare_a@epitech.net>
##
## Started on  ven. avril 17 02:26:49 2015 Antoine Favarel
## Last update sam. mai 23 20:36:26 2015 Antoine Favarel
##

CC=		cc
CFLAGS=		-Wall -Wextra -pedantic -ansi -g -D_REENTRANT -D_GNU_SOURCE
CFLAGS+=	-Wno-unused-parameter
CFLAGS+=	-I include/ -I include/neptune/
CXFLAGS=	-o

LDFLAGS=	-lpthread

AR=		ar
ARFLAGS=	rcs

RM=		rm
RMFLAGS=	-fr

NAME=		libneptune.a

MAIN=

SRC=		$(MAIN) \
		src/clust/dispatcher/delete_dispatcher.c \
		src/clust/dispatcher/dispatcher_connection.c \
		src/clust/dispatcher/dispatcher_open.c \
		src/clust/dispatcher/dispatcher_update.c \
		src/clust/dispatcher/init_dispatcher.c \
		src/clust/dispatcher/new_dispatcher.c \
		src/clust/dispatcher/uninit_dispatcher.c \
		src/clust/manager/delete_manager.c \
		src/clust/manager/init_manager.c \
		src/clust/manager/manager_main.c \
		src/clust/manager/manager_open.c \
		src/clust/manager/manager_update.c \
		src/clust/manager/new_manager.c \
		src/clust/manager/uninit_manager.c \
		src/clust/protocole/new_metadata.c \
		src/io/delete_io.c \
		src/io/init_io.c \
		src/io/io_assync.c \
		src/io/io_close.c \
		src/io/io_gets.c \
		src/io/io_lock.c \
		src/io/io_nextline.c \
		src/io/io_open.c \
		src/io/io_puts.c \
		src/io/io_unlock.c \
		src/io/new_io.c \
		src/io/uninit_io.c \
		src/data/data_check.c \
		src/data/data_load.c \
		src/data/data_lock.c \
		src/data/data_save.c \
		src/data/data_set_dupmem.c \
		src/data/data_set_mem.c \
		src/data/data_unlock.c \
		src/data/data_x.c \
		src/data/delete_data.c \
		src/data/init_data.c \
		src/data/new_data.c \
		src/data/uninit_data.c \
		src/list/delete_elem.c \
		src/list/delete_list.c \
		src/list/elem_dup.c \
		src/list/init_elem.c \
		src/list/init_list.c \
		src/list/list_add_first.c \
		src/list/list_add_last.c \
		src/list/list_at.c \
		src/list/list_check.c \
		src/list/list_load.c \
		src/list/list_lock.c \
		src/list/list_next.c \
		src/list/list_pop.c \
		src/list/list_popret.c \
		src/list/list_get.c \
		src/list/list_prev.c \
		src/list/list_put.c \
		src/list/list_push.c \
		src/list/list_remove.c \
		src/list/list_remove_at.c \
		src/list/list_rewind.c \
		src/list/list_save.c \
		src/list/list_seek.c \
		src/list/list_swap.c \
		src/list/list_swap_at.c \
		src/list/list_unlock.c \
		src/list/new_elem.c \
		src/list/new_init_dynamic_elem.c \
		src/list/new_init_static_elem.c \
		src/list/new_list.c \
		src/list/uninit_elem.c \
		src/list/uninit_list.c \
		src/monad/delete_monad.c \
		src/monad/init_monad.c \
		src/monad/monad_main.c \
		src/monad/monad_start.c \
		src/monad/monad_stop.c \
		src/monad/monad_update.c \
		src/monad/new_monad.c \
		src/monad/uninit_monad.c \
		src/server/delete_server.c \
		src/server/init_server.c \
		src/server/new_server.c \
		src/server/server_close.c \
		src/server/server_main.c \
		src/server/server_open.c \
		src/server/uninit_server.c \
		src/socket/new_socket.c \
		src/socket/init_socket.c \
		src/socket/socket_main.c \
		src/socket/socket_open.c \
		src/socket/uninit_socket.c \
		src/socket/delete_socket.c \
		src/strmut/sm_cat.c \
		src/strmut/sm_cmp.c \
		src/strmut/sm_copy.c \
		src/strmut/sm_dup.c \
		src/strmut/sm_dupc.c \
		src/strmut/sm_dupn.c \
		src/strmut/sm_egal.c \
		src/strmut/sm_epurestr.c \
		src/strmut/sm_fillbuff.c \
		src/strmut/sm_fromint.c \
		src/strmut/sm_getdigits.c \
		src/strmut/sm_getint.c \
		src/strmut/sm_getlong.c \
		src/strmut/sm_getmint.c \
		src/strmut/sm_getmlong.c \
		src/strmut/sm_getmuint.c \
		src/strmut/sm_getmulong.c \
		src/strmut/sm_getuint.c \
		src/strmut/sm_getulong.c \
		src/strmut/sm_is_strcontainc.c \
		src/strmut/sm_len.c \
		src/strmut/sm_lento.c \
		src/strmut/sm_mulsplit.c \
		src/strmut/sm_replacec.c \
		src/strmut/sm_split.c \
		src/strmut/sm_splithead.c \
		src/strmut/sm_splittail.c \
		src/system/delete_system.c \
		src/system/init_system.c \
		src/system/new_enventry.c \
		src/system/new_opt.c \
		src/system/new_system.c \
		src/system/system_env.c \
		src/system/system_getenv.c \
		src/system/system_getopt.c \
		src/system/system_isenable.c \
		src/system/system_print.c \
		src/system/system_setenv.c \
		src/system/system_st_initargs.c \
		src/system/system_st_initenv_list.c \
		src/system/system_st_initopts.c \
		src/system/system_unsetenv.c \
		src/system/uninit_system.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
      ifeq ($(NAME), libneptune.a)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
      else
	$(CC) $(CXFLAGS) $(NAME) $(OBJ) $(LDFLAGS)
      endif

clean:
	$(RM) $(RMFLAGS) $(OBJ)

fclean:		clean
	$(RM) $(RMFLAGS) $(NAME)

re:		fclean all

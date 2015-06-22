##
## Makefile for 42sh in /home/zack/Epitech/42sh
##
## Made by Antoine Favarel
## Login   <favare_a@epitech.net>
##
## Started on  ven. mai 22 17:27:35 2015 Antoine Favarel
## Last update dim. mai 24 22:27:40 2015 Antoine Favarel
##


CC=		cc
CFLAGS	=	-Wall -Wextra -ansi -pedantic -D_REENTRANT -I./include/
CFLAGS	+=	-Wno-unused-parameter
LDFLAGS=	-L./lib/ -lneptune -lpthread -lncurses

NAME=		42sh

RM=		rm
RMFLAGS=	-fr

SRC=		src/coquillage/b_alias.c \
		src/coquillage/b_cd.c \
		src/coquillage/b_echo.c \
		src/coquillage/b_env.c \
		src/coquillage/b_setenv.c \
		src/coquillage/b_setfmstr.c \
		src/coquillage/b_unsetenv.c \
		src/coquillage/c_and.c \
		src/coquillage/c_builtin.c \
		src/coquillage/c_dredl.c \
		src/coquillage/c_dredr.c \
		src/coquillage/c_exec.c \
		src/coquillage/c_norm.c \
		src/coquillage/c_or.c \
		src/coquillage/c_pipe.c \
		src/coquillage/c_redl.c \
		src/coquillage/c_redr.c \
		src/coquillage/c_semicolon.c \
		src/coquillage/execute.c \
		src/coquillage/free_execute.c \
		src/coquillage/free_node.c \
		src/coquillage/free_stack.c \
		src/coquillage/free_token.c \
		src/coquillage/free_tree.c \
		src/coquillage/getabspath.c \
		src/coquillage/getargs.c \
		src/coquillage/getexecute.c \
		src/coquillage/getid.c \
		src/coquillage/gettoken.c \
		src/coquillage/lexer.c \
		src/coquillage/new_execute.c \
		src/coquillage/new_node.c \
		src/coquillage/new_token.c \
		src/coquillage/shell.c \
		src/coquillage/shell_prompt.c \
		src/coquillage/shell_string.c \
		src/coquillage/splitcmd.c \
		src/coquillage/tokenize.c \
		src/coquillage/translate.c \
		src/coquillage/tree.c \
		src/main.c

OBJ=		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/neptune/ re
	cp ./lib/neptune/libneptune.a ./lib/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(RMFLAGS) $(OBJ)
	make -C ./lib/neptune/ clean

fclean:		clean
	$(RM) $(RMFLAGS) $(NAME)

re:		fclean all

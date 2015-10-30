CC          = gcc
NAME        = libk.a
SRC         =	\
			terminit.c	\
			myputc.c	\
			single_tattr.c	\
			single_termbuf.c	\

OBJDIR			= ./obj/
OBJ         = $(addprefix $(OBJDIR), $(SRC:.c=.o))
HDFLAGS     = -I.
LDFLAGS     = -ltermcap
CFLAGS      =	$(HDFLAGS) -Wall -Werror -Wextra -ansi -pedantic -g
RM          = rm -rf


all:        $(NAME)

$(NAME):    $(OBJ)
			@echo "\033[1;32m[Linking] \t\033[0m: \033[0;32m" | tr -d '\n'
			ar rc $@ $^ 
			ranlib $@
			@echo "\033[0m" | tr -d '\n'

$(addprefix $(OBJDIR), %.o):        %.c
			@echo "\033[1;36m[Compiling] \t\033[0m: \033[1;37m" | tr -d '\n'
			$(CC) $(CFLAGS) -c $< -o $@
			@echo "\033[0m" | tr -d '\n'

re:         fclean all

.PHONY:     all clean re fclean

clean:
			@echo "\033[1;33m[Cleaning] \t\033[0m: \033[0;31m" | tr -d '\n'
			$(RM) $(OBJ)
			@echo "\033[0m" | tr -d '\n'

fclean:     clean
			@echo "\033[1;31m[Fcleaning] \t\033[0m: \033[0;31m" | tr -d '\n'
			$(RM) $(NAME)
			@echo "\033[0m" | tr -d '\n'

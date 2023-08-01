SRCS =	push_swap.c build_stack.c movements.c errors.c sorting_stuff.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap.a
HEADER = push_swap.h
HEADER_LIBFT = libft/libft.h
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${HEADER}
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

all: make_libs ${NAME}

make_libs:
	make -C ft_printf/

${NAME}: ${OBJS}
	cp ft_printf/libftprintf.a ${NAME}
	ar crs ${NAME} ${OBJS}

leaks:
	leaks -atExit -- ./a.out ${ARGS}

norm:
	norminette ${SRCS}

run: ${NAME} make_libs
	cc ${CFLAGS} push_swap.c ${NAME}

clean:
	@rm -f ${OBJS} $ ${OBJS_BONUS}
	MAKE -C ft_printf clean

fclean:	clean
	@rm -f ${NAME}
	rm -f bonus do_bonus
	rm ./a.out
	MAKE -C ft_printf fclean

re:	fclean all

.PHONY: all clean fclean re

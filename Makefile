SRCS =	push_swap.c build_stack.c movements.c errors.c sorting_stuff.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap.a
HEADER = push_swap.h
HEADER_LIBFT = libft/libft.h
CFLAGS = -Wall -Wextra -Werror
BIN = push_swap

%.o: %.c ${HEADER}
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

all: make_libs ${NAME}

make_libs:
	@make -C ft_printf/ --no-print-directory

${NAME}: ${OBJS}
	cp ft_printf/libftprintf.a ${NAME}
	ar crs ${NAME} ${OBJS}

leaks:
	leaks -atExit -- ./${BIN} ${ARGS}

norm:
	norminette ${SRCS}

run: all
	cc ${CFLAGS} push_swap.c ${NAME} -o ${BIN}
	@#./${BIN} ${ARGS}

clean:
	@rm -f ${OBJS} $ ${OBJS_BONUS}
	@make -C ft_printf clean --no-print-directory

fclean:	clean
	@rm -f ${NAME}
	rm -f bonus do_bonus
	rm -f ${BIN}
	@make -C ft_printf fclean --no-print-directory

re:	fclean all

.PHONY: all clean fclean re

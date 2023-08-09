# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 11:31:39 by nuferron          #+#    #+#              #
#    Updated: 2023/08/09 15:37:53 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c stack_utils.c movements.c errors.c sorting_till_five.c \
		get_stack.c utils.c sorting_algorithm.c

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
	make -C ft_printf norm --no-print-directory
	norminette ${SRCS} | grep -v "OK" | awk '{if($$2 == "Error!") \
	print "\033[1;31;m"$$1" "$$2; else print "\033[0;m"$$0}'

run: all
	@cc ${CFLAGS} push_swap.c ${NAME} -o ${BIN}
	@./${BIN} `ruby -e "puts (1..${MAX}).to_a.shuffle.join(' ')"` | wc -l

clean:
	@rm -f ${OBJS} $ ${OBJS_BONUS}
	@make -C ft_printf clean --no-print-directory

fclean:	clean
	@rm -f ${NAME}
	rm -f bonus do_bonus
	rm -f ${BIN}
	@make -C ft_printf fclean --no-print-directory

re:	fclean all

.SILENT: norm do_bonus make_libs
.PHONY: all clean fclean re

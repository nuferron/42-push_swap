# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 11:31:39 by nuferron          #+#    #+#              #
#    Updated: 2023/08/13 18:14:01 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c stack_utils.c movements.c errors.c sorting_till_five.c \
		get_stack.c utils.c sorting_algorithm.c

SRCS_BONUS = bonus/checker.c inc/gnl/gnl.c inc/gnl/gnl_utils.c stack_utils.c \
		movements.c errors.c get_stack.c utils.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = push_swap.a
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
BIN = push_swap
BIN_BONUS = checker
MAX = 100
NUMS := `ruby -e "puts (1..${MAX}).to_a.shuffle.join(' ')"`

%.o: %.c ${HEADER}
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

all: make_libs ${NAME}

make_libs:
	@make -C inc/ft_printf/ --no-print-directory

${NAME}: ${OBJS}
	cp inc/ft_printf/libftprintf.a ${NAME}
	ar crs ${NAME} ${OBJS}
	@cc ${CFLAGS} push_swap.c ${NAME} -o ${BIN}

leaks: all
	leaks -atExit -- ./${BIN} ${NUMS}
norm:
	make -C inc/ft_printf norm --no-print-directory
	norminette ${SRCS} | grep -v "OK" | awk '{if($$2 == "Error!") \
	print "\033[1;31;m"$$1" "$$2; else print "\033[0;m"$$0}'

run: all
	@./${BIN} ${NUMS}
	@echo ${NUMS} > combination

bonus: ${OBJS_BONUS} all
	cc ${CFLAGS} ${SRCS_BONUS} ${NAME} -o ${BIN_BONUS}

clean:
	rm -f ${OBJS} $ ${OBJS_BONUS}
	@make -C inc/ft_printf clean --no-print-directory

fclean:	clean
	rm -f ${NAME}
	rm -f ${BIN}
	rm -rf bonus
	rm -f ${BIN_BONUS}
	@make -C inc/ft_printf fclean --no-print-directory

re:	fclean all

.SILENT: norm make_libs
.PHONY: all clean fclean re

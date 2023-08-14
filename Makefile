# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 11:31:39 by nuferron          #+#    #+#              #
#    Updated: 2023/08/14 20:14:36 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	push_swap.c stack_utils.c movements.c errors.c sorting_till_five.c \
		get_stack.c utils.c sorting_algorithm.c

SRCS_BNS = ps_bonus/checker.c inc/gnl/gnl.c inc/gnl/gnl_utils.c stack_utils.c \
		movements.c errors.c get_stack.c utils.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap.a
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
BIN = push_swap
BIN_BNS = checker
MAX = 100
NUMS := `ruby -e "puts (1..${MAX}).to_a.shuffle.join(' ')"`
#NUMS := $(shell ruby -e "puts (1..$(MAX).to_a.shuffle.join(' '))")

%.o: %.c ${HEADER}
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

all: make_libs ${NAME}

test:
	echo $(NUMS)

make_libs:
	@make -C inc/ft_printf/ --no-print-directory

${NAME}: ${OBJS}
	cp inc/ft_printf/libftprintf.a ${NAME}
	ar crs ${NAME} ${OBJS}
	@cc ${CFLAGS} push_swap.c ${NAME} -o ${BIN}

leaks: | all
	leaks -atExit -- ./${BIN} ${NUMS}

norm:
	make -C inc/ft_printf norm --no-print-directory
	norminette ${SRCS} ${SRCS_BNS} | grep -v "OK" | awk '{if($$2 == "Error!") \
	print "\033[1;31;m"$$1" "$$2; else print "\033[0;m"$$0}'

run: | all
	@./${BIN} ${NUMS}
	@echo ${NUMS} > combination

bonus: | all
	cc ${CFLAGS} ${SRCS_BNS} ${NAME} -o ${BIN_BNS}
	@touch $@

leaks_bonus: | all bonus
	@echo $(NUMS) > combination
	$(eval FINAL_NUMS := $(shell cat combination))
	./${BIN} ${FINAL_NUMS} | leaks -atExit -- ./${BIN_BNS} ${FINAL_NUMS}
	@rm -f combination

clean:
	rm -f ${OBJS} $ ${OBJS_BNS}
	@make -C inc/ft_printf clean --no-print-directory

fclean:	clean
	rm -f ${NAME} ${BIN} ${BIN_BNS} bonus libftprintf.a
	@make -C inc/ft_printf fclean --no-print-directory

re:	fclean all

.SILENT: norm make_libs
.PHONY: all clean fclean re

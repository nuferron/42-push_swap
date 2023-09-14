# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 11:31:39 by nuferron          #+#    #+#              #
#    Updated: 2023/09/14 14:53:32 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

SRCS =	push_swap.c stack_utils.c movements.c errors.c \
		sorting_till_five.c get_stack.c utils.c \
		sorting_algorithm.c

SRCS_BNS =	checker.c checker_do.c stack_utils.c \
			movements.c errors.c get_stack.c utils.c

OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJS_BNS = $(addprefix $(OBJDIR_BNS),$(SRCS_BNS:.c=.o))

SRCDIR = src/
SRCDIR_BNS = src_bonus/
OBJDIR = obj/
OBJDIR_BNS = obj_bonus/
NAME = push_swap
LIB = inc/ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
BIN_BNS = checker
MAX = 100
NUMS := `ruby -e "puts (1..${MAX}).to_a.shuffle.join(' ')"`
COLUMNS = $(shell tput cols)

all: make_libs ${NAME}

test:
	echo $(NUMS)

make_libs:
	make -C inc/ft_printf/ bonus --no-print-directory

${NAME}: ${OBJS}
	cc ${CFLAGS} ${OBJS} ${LIB} -o $@
	printf "${WHITE}PUSH_SWAP: ${GREEN}Binary compiled!${RESET}\n"

leaks: | all
	leaks -atExit -- ./${BIN} ${NUMS}

norm:
	make -C inc/ft_printf norm --no-print-directory
	norminette ${SRCS} ${SRCS_BNS} ${HEADERS} | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "\033[1;31;m"$$1" "$$2; \
	else print "\033[0;m"$$0}'

${OBJDIR}%.o: ${SRCDIR}%.c ${HEADER}
	@printf "${WHITE}PUSH_SWAP: ${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
	@mkdir -p $(dir $@)
	@cc ${CFLAGS} -c $< -o $@
	@printf "\r%-${COLUMNS}s\r"

${OBJDIR_BNS}%.o: ${SRCDIR_BNS}%.c ${HEADER}
	@printf "${WHITE}PUSH_SWAP: ${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
	@mkdir -p $(dir $@)
	@cc ${CFLAGS} -c $< -o $@
	@printf "\r%-${COLUMNS}s\r"

run: | all
	@./${BIN} ${NUMS}
	@echo ${NUMS} > combination

bonus: ${OBJS_BNS} | all
	cc ${CFLAGS} ${OBJS_BNS} ${LIB} -o ${BIN_BNS}
	printf "${WHITE}PUSH_SWAP: ${GREEN}Binary compiled!${RESET}\n"
	touch $@

leaks_bonus: | all bonus
	echo $(NUMS) > combination
	$(eval FINAL_NUMS := $(shell cat combination))
	./${BIN} ${FINAL_NUMS} | leaks -atExit -- ./${BIN_BNS} ${FINAL_NUMS}
	rm -f combination

clean:
	if [ -d ${OBJDIR} ] || [ -d ${OBJDIR_BNS} ]; then \
		rm -rf ${OBJDIR} ${OBJDIR_BNS} combination; \
		printf "${WHITE}PUSH_SWAP: ${RED}Objects have been deleted${RESET}\n"; \
	fi
	make -C inc/ft_printf clean --no-print-directory

fclean: 	clean
	if [ -e ${NAME} ] || [ -e do_bonus ] ; then \
		rm -f ${NAME} ${BIN_BNS} do_bonus ; \
		printf "${WHITE}PUSH_SWAP: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else printf "${WHITE}PUSH_SWAP: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi
	make -C inc/ft_printf fclean --no-print-directory

re:	fclean all

.SILENT: norm make_libs bonus ${NAME} leaks leaks_bonus clean fclean
.PHONY: all clean fclean re

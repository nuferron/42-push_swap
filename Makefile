# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/09 11:31:39 by nuferron          #+#    #+#              #
#    Updated: 2023/10/23 21:40:59 by nuferron         ###   ########.fr        #
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
LIB = libft/libft.a
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
BIN_BNS = checker
MAX = 100
NUMS := `ruby -e "puts (1..${MAX}).to_a.shuffle.join(' ')"`
COLUMNS = $(shell tput cols)
HEADER = push_swap.h

all: make_libs ${NAME}

test:
	echo $(NUMS)

make_libs:
	make -C libft/ --no-print-directory

${NAME}: ${OBJS}
	cc ${CFLAGS} ${OBJS} ${LIB} -o $@
	printf "${WHITE}PUSH_SWAP: ${GREEN}Binary compiled!${RESET}\n"

norm:
	make -C libft/ --no-print-directory
	printf "${WHITE}PUSH_SWAP${RESET}\n"
	norminette $(addprefix ${SRCDIR},$(SRCS)) $(addprefix ${SRCDIR_BNS},$(SRCS_BNS)) ${HEADER} | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "${RED}"$$1" "$$2; \
	else print "${RESET}"$$0}'


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
	@./${NAME} ${NUMS}
	@echo ${NUMS} > combination

bonus: ${OBJS_BNS} | all
	cc ${CFLAGS} ${OBJS_BNS} ${LIB} -o ${BIN_BNS}
	printf "${WHITE}PUSH_SWAP: ${GREEN}Binary compiled!${RESET}\n"
	touch $@

clean:
	if [ -d ${OBJDIR} ] || [ -d ${OBJDIR_BNS} ]; then \
		rm -rf ${OBJDIR} ${OBJDIR_BNS} combination; \
		printf "${WHITE}PUSH_SWAP: ${RED}Objects have been deleted${RESET}\n"; \
	fi
	make -C libft clean --no-print-directory

fclean: 	clean
	if [ -e ${NAME} ] || [ -e do_bonus ] ; then \
		rm -f ${NAME} ${BIN_BNS} do_bonus ; \
		printf "${WHITE}PUSH_SWAP: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else printf "${WHITE}PUSH_SWAP: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi
	make -C libft fclean --no-print-directory

re:	fclean all

.SILENT: make_libs bonus ${NAME} clean fclean norm
.PHONY: all clean fclean re

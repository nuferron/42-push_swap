# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 18:05:14 by nuferron          #+#    #+#              #
#    Updated: 2024/03/11 14:33:38 by nuferron         ###   ########.fr        #
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

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	   ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c hex_len.c unsigned_len.c \
	   int_len.c gnl/gnl.c gnl/gnl_utils.c

SRCS_BNS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJS_BNS = $(addprefix $(OBJDIR), $(addprefix bonus/, $(SRCS_BNS:.c=.o)))
OBJDIR = obj/
SRCDIR = src/
HEADER = libft.h
NAME = libft.a
LIBP = ft_printf/libft_printf.a
CFLAGS = -Wall -Wextra -Werror
COLUMNS = $(shell tput cols)

all: 		${NAME}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}
		printf "${WHITE}LIBFT: ${GREEN}Library compiled!${RESET}\n"
		${MAKE} -s make_printf

bonus:	do_bonus

make_printf:
		rm -f ft_printf/do_bonus
		make -C ft_printf bonus --no-print-directory
		${MAKE} combine_libs


combine_libs: ${NAME} ${LIBP}
		rm ${NAME}
		mkdir -p tmp
		cp -r obj/*.o tmp/.
		cp -r obj/*/*.o tmp/.
		cp -r ft_printf/obj_bonus/*.o tmp/.
		ar -crs ${NAME} tmp/*.o
		rm -rf tmp

do_bonus:	${OBJS} ${OBJS_BNS}
		ar rcs ${NAME} ${OBJS} ${OBJS_BNS}
		printf "${WHITE}LIBFT: ${GREEN}Bonus compiled!${RESET}\n"
		${MAKE} -s make_printf
		touch do_bonus

norm:
	make -C ft_printf norm --no-print-directory
	printf "${WHITE}LIBFT${RESET}"
	(norminette ${SRCDIR} && echo " ${GREEN}Everything is correct")  | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "\n${RED}"$$1" "$$2; \
	else print "${RESET}"$$0}'

$(OBJDIR)%.o:	${SRCDIR}%.c $(HEADER) Makefile
		@mkdir -p $(dir $@)
		@mkdir -p ${OBJDIR}/bonus
		@mkdir -p ${OBJDIR}/gnl
		@printf "${WHITE}LIBFT:${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
		@cc $(CFLAGS) -I . -c $< -o $@
		@printf "\r%-${COLUMNS}s\r" ""

clean:
		make -C ft_printf clean --no-print-directory
		if [ -d ${OBJDIR} ] ; then \
			rm -rf ${OBJDIR} ; \
			printf "${WHITE}LIBFT: ${RED}Objects have been deleted${RESET}\n" ; \
		fi

fclean: 	clean
		make -C ft_printf fclean --no-print-directory
		if [ -e ${NAME} ] || [ -e do_bonus ] ; then \
			rm -rf ${NAME} do_bonus ; \
			printf "${WHITE}LIBFT: ${RED}Static library has been deleted${RESET}\n" ; \
		else printf "${WHITE}LIBFT: ${PURPLE}Already cleaned${RESET}\n" ; \
		fi

re:		fclean all

.SILENT: fclean clean do_bonus norm make_printf combine_libs ${NAME}
.PHONY: all clean fclean re bonus make_printf

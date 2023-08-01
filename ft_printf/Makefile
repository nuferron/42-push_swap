# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 00:01:43 by nuferron          #+#    #+#              #
#    Updated: 2023/05/14 17:26:24 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c printf_char.c printf_string.c printf_num.c \
		printf_unsigned_num.c printf_pointers.c printf_hex_cap.c \
		printf_hex_min.c \

SRCS_BONUS =	ft_printf_bonus.c printf_char_bonus.c printf_string_bonus.c \
				printf_num_bonus.c 	printf_unsigned_num_bonus.c \
				printf_pointers_bonus.c printf_hex_cap_bonus.c \
				printf_hex_min_bonus.c printf_percentage.c pf_bonus_padding.c \
				pf_bonus_flags.c pf_bonus_hexadecimal.c pf_bonus_precision.c \
				pf_bonus_sign.c len_functions.c \


OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}


NAME = libftprintf.a
HEADER = libftprintf.h
HEADER_LIBFT = libft/libft.h
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${HEADER}
	cc ${CFLAGS} -c $< -o ${<:.c=.o}
all: make_libs ${NAME}

bonus: make_libs do_bonus

make_libs:
	MAKE -C libft/

${NAME}: ${OBJS}
	cp libft/libft.a $(NAME)
	ar crs ${NAME} ${OBJS}

do_bonus: ${OBJS_BONUS} ${HEADER_LIBFT}
	cp libft/libft.a $(NAME)
	ar crs ${NAME} ${OBJS_BONUS}
	touch do_bonus

clean:
	@rm -f ${OBJS} $ ${OBJS_BONUS}
	MAKE -C libft clean

fclean:	clean
	@rm -f ${NAME}
	rm -f bonus do_bonus
	MAKE -C libft fclean

re:	fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus

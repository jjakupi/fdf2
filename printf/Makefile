# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjakupi <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 14:55:57 by jjakupi           #+#    #+#              #
#    Updated: 2024/10/25 12:35:23 by jjakupi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Definitons
NAME		= libftprintf.a

HEAD		= ft_printf.h

FILES		= ft_printf.c \
			  printf_char.c \
			  printf_hexdec_l.c \
			  printf_hexdec_u.c \
			  printf_perce.c \
			  printf_string.c \
			  printf_num.c \
			  printf_numu.c \
			  printf_ptr.c \

MAIN_FILE	= ./test/main.c

OBJS			= $(FILES:.c=.o)

LIBFT_DIR	= ./libft/

LIBFT		= $(LIBFT_DIR)libft.a

#Creation commands
CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM 			= rm -f

#Actions
all:		$(NAME)

%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
			make -C $(LIBFT_DIR) all

$(NAME):	$(OBJS) $(LIBFT)
				cp $(LIBFT) $(NAME)
				$(AR) $(NAME) $(OBJS)

#Action commands
run:		$(NAME)
				$(CC) $(CFLAGS) $(MAIN_FILE) $(NAME)
				./a.out
clean:
			make -C $(LIBFT_DIR) clean
			$(RM) $(OBJS)

fclean:		clean
				make -C $(LIBFT_DIR) fclean
				$(RM) $(NAME)

re: 		fclean all

.PHONY:		all, clean, fclean, re, libft

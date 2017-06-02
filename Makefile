# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyoung <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/19 12:53:47 by lyoung            #+#    #+#              #
#    Updated: 2017/06/02 12:25:59 by lyoung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra

LIBFT_SRC = libft/ft_putchar.c \
	   libft/ft_putstr.c \
	   libft/ft_putendl.c \
	   libft/ft_putnbr.c \
	   libft/ft_putchar_fd.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_putendl_fd.c \
	   libft/ft_putnbr_fd.c \
	   libft/ft_strlen.c \
	   libft/ft_strdup.c \
	   libft/ft_strndup.c \
	   libft/ft_strcpy.c \
	   libft/ft_strncpy.c \
	   libft/ft_strcmp.c \
	   libft/ft_strncmp.c \
	   libft/ft_strcat.c \
	   libft/ft_strncat.c \
	   libft/ft_strlcat.c \
	   libft/ft_strchr.c \
	   libft/ft_strrchr.c \
	   libft/ft_strstr.c \
	   libft/ft_strnstr.c \
	   libft/ft_strnew.c \
	   libft/ft_strdel.c \
	   libft/ft_strclr.c \
	   libft/ft_striter.c \
	   libft/ft_striteri.c \
	   libft/ft_strmap.c \
	   libft/ft_strmapi.c \
	   libft/ft_strequ.c \
	   libft/ft_strnequ.c \
	   libft/ft_strsub.c \
	   libft/ft_strjoin.c \
	   libft/ft_strtrim.c \
	   libft/ft_strsplit.c \
	   libft/ft_isalpha.c \
	   libft/ft_isdigit.c \
	   libft/ft_isalnum.c \
	   libft/ft_isascii.c \
	   libft/ft_isprint.c \
	   libft/ft_isspace.c \
	   libft/ft_bzero.c \
	   libft/ft_memset.c \
	   libft/ft_memcpy.c \
	   libft/ft_memccpy.c \
	   libft/ft_memmove.c \
	   libft/ft_memchr.c \
	   libft/ft_memcmp.c \
	   libft/ft_memalloc.c \
	   libft/ft_memdel.c \
	   libft/ft_atoi.c \
	   libft/ft_toupper.c \
	   libft/ft_tolower.c \
	   libft/ft_itoa.c \
	   libft/ft_itoa_base.c \
	   libft/ft_uinttoa_base.c \
	   libft/ft_lstnew.c \
	   libft/ft_lstdelone.c \
	   libft/ft_lstdel.c \
	   libft/ft_lstadd.c \
	   libft/ft_lstiter.c \
	   libft/ft_lstmap.c \

SRC = srcs/ft_printf.c \
	  srcs/ft_vprintf.c \
	  srcs/build.c \
	  srcs/modifiers.c \
	  srcs/conversions.c \
	  srcs/handle_length.c \
	  srcs/handle_diuox.c \
	  srcs/handle_scp.c \
	  srcs/handle_extra.c

OBJ = $(SRC:.c=.o)

OBJ_LIBFT = $(LIBFT_SRC:.c=.o)

all: $(NAME)

$(OBJ): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(OBJ_LIBFT): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(OBJ_LIBFT) $(OBJ)
	@ar rc $(NAME) $(OBJ_LIBFT) $(OBJ)
	@echo "\033[32m- libftprintf.a compiled\033[0m"

clean:
	@rm -rf $(OBJ) $(OBJ_LIBFT)
	@echo "\033[31m- object files removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m- libftprintf.a removed\033[0m"

re: fclean all

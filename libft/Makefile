# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 18:29:24 by jamendoe          #+#    #+#              #
#    Updated: 2022/11/12 18:29:30 by jamendoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MANDATORY = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_printf.c \
			ft_print_numberhex.c \
			ft_print_pointer.c \
			ft_print_ui_number.c \
			ft_pf_putchar.c \
			ft_pf_putstr.c \
			ft_pf_putnbr.c \
			ft_pf_putusnbr.c

MANDATORYO = $(MANDATORY:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror -std=c99

REMOVE = rm -rf

AR = ar crs

all: $(NAME)

$(NAME): $(MANDATORYO)
	$(AR) $(NAME) $(MANDATORYO)

clean:
	$(REMOVE) $(MANDATORYO)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
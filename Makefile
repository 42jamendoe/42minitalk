# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 18:17:48 by jamendoe          #+#    #+#              #
#    Updated: 2023/02/16 18:17:50 by jamendoe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MT_NAME = server client
MT_NAME_BONUS = server client server_bonus client_bonus
LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRCDIR = ./src

SRC = $(foreach name, $(MT_NAME), $(addsuffix .c, $(addsuffix /, $(SRCDIR))$(name))) ./src/minitalk_utils.c
OBJ = $(foreach name, $(MT_NAME), $(addsuffix .o, $(addsuffix /, $(SRCDIR))$(name))) ./src/minitalk_utils.o
SRC_B = $(foreach name, $(MT_NAME_BONUS), $(addsuffix .c, $(addsuffix /, $(SRCDIR))$(name))) ./src/minitalk_bonus_utils.c
OBJ_B = $(foreach name, $(MT_NAME_BONUS), $(addsuffix .o, $(addsuffix /, $(SRCDIR))$(name))) ./src/minitalk_bonus_utils.o

all: $(MT_NAME) $(LIBFT)

$(LIBFT):
	$(MAKE) -C libft

server: ./src/server.o ./src/minitalk_utils.o $(LIBFT)
	$(CC) $(CFLAGS) ./src/server.o ./src/minitalk_utils.o $(LIBFT) -o server

client: ./src/client.o ./src/minitalk_utils.o $(LIBFT)
	$(CC) $(CFLAGS) ./src/client.o ./src/minitalk_utils.o $(LIBFT) -o client

bonus: $(MT_NAME_BONUS)

server_bonus: ./src/server_bonus.o ./src/minitalk_bonus_utils.o $(LIBFT)
	$(CC) $(CFLAGS) ./src/server_bonus.o ./src/minitalk_bonus_utils.o $(LIBFT) -o server_bonus

client_bonus: ./src/client_bonus.o ./src/minitalk_bonus_utils.o $(LIBFT)
	$(CC) $(CFLAGS) ./src/client_bonus.o ./src/minitalk_bonus_utils.o $(LIBFT) -o client_bonus

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJ) $(OBJ_B)
	
fclean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJ) $(OBJ_B)
	$(RM) $(MT_NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
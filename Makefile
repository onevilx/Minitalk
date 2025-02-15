# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 16:08:56 by yaboukir          #+#    #+#              #
#    Updated: 2025/02/15 14:41:37 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = client.c ft_helpers.c
SRCS_S = server.c ft_helpers.c
SRCS_C_BONUS = client_bonus.c ft_helpers.c
SRCS_S_BONUS = server_bonus.c ft_helpers.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
OBJS_S_BONUS = $(SRCS_S_BONUS:.c=.o)
OBJS_C_BONUS = $(SRCS_C_BONUS:.c=.o)

CC = cc
AR = ar r
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME_C = client
NAME_S = server
NAME_C_BONUS = client_bonus
NAME_S_BONUS = server_bonus
INCLUDE = minitalk.h

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S)

bonus: $(NAME_C_BONUS) $(NAME_S_BONUS)

$(NAME_C_BONUS): $(OBJS_C_BONUS)
	$(CC) $(CFLAGS) $(OBJS_C_BONUS) -o $(NAME_C_BONUS)

$(NAME_S_BONUS): $(OBJS_S_BONUS)
	$(CC) $(CFLAGS) $(OBJS_S_BONUS) -o $(NAME_S_BONUS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_C) $(OBJS_S) $(OBJS_C_BONUS) $(OBJS_S_BONUS)

fclean: clean
	$(RM) $(NAME_C) $(NAME_S) $(NAME_C_BONUS) $(NAME_S_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus

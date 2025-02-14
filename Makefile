# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 16:08:56 by yaboukir          #+#    #+#              #
#    Updated: 2025/02/14 15:23:47 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C = client.c ft_helpers.c
SRCS_S = server.c ft_helpers.c

#SRCS_MINITALK_BONUS = 

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)


#OBJS_MINITALK_BONUS = $(SRCS_MINITALK_BONUS:.c=.o)


CC = cc
AR = ar r
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = minitalk.h
#INCLUDE_BONUS = bonus/minitalk.h
NAME_C = client
NAME_S = server 
#NAME_MINITALK_BONUS = 

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S)

#bonus: $(NAME_MINITALK_BONUS)

#$(NAME_MINITALK_BONUS): $(OBJS_MINITALK_BONUS)
#	$(CC) $(CFLAGS) $(OBJS_MINITALK_BONUS) -o $(NAME_MINITALK_BONUS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

#bonus/%.o: bonus/%.c $(INCLUDE_BONUS)
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_C) $(OBJS_C) 
# $(OBJS_MINITALK_BONUS)

fclean: clean
	$(RM) $(NAME_C) $(NAME_S) 
# $(NAME_MINITALK_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 22:40:02 by joshapir          #+#    #+#              #
#    Updated: 2025/04/14 22:11:55 by joshapir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
# NAME_BONUS =

SRC = pipex.c ft_strncmp.c ft_strlen.c ft_strjoin.c ft_split.c cleanup.c \
      init_children_and_parsing.c path_and_exeve.c

INCLUDE = pipex.h
# INCLUDE_BONUS =

CFLAGS = -Wall -Werror -Wextra
CC  = cc

OBJ = $(SRC:.c=.o)

# OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
# bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

#$(NAME_BONUS): $(OBJ_BONUS) $(INCLUDE_BONUS)
#		$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c  Makefile pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all		

.PHONY: all clean fclean re


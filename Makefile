# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 22:07:22 by meghribe          #+#    #+#              #
#    Updated: 2024/11/18 09:49:38 by meghribe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -rf

CC = cc
CFLAGS = -Wall -Wextra -Werror
SANITIZE = -g#-fsanitize=address

NAME = push_swap
INCLUDE = push_swap.h

SRC = args_utils.c ft_split.c libft.c lst_utils.c handle_args.c \
      index.c small_sort.c radix_sort.c movements.c main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SANITIZE) $(OBJ) -o $(NAME)

%.o: %.c $(INCLUDE) Makefile
	$(CC) $(CFLAGS) $(SANITIZE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

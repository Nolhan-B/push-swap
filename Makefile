# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 09:21:42 by nbarbosa          #+#    #+#              #
#    Updated: 2025/12/15 16:04:29 by nbarbosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I .

NAME = push_swap
SRC = \
utils.c \
stack_utils.c \
push_swap.c\
check_error.c\
complex_sort.c\
medium_sort.c\
simple_sort.c\
sort_utils.c

	
OBJ = $(SRC:.c=.o)  

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
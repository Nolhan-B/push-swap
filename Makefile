# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbilyj <nbilyj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 09:21:42 by nbarbosa          #+#    #+#              #
#    Updated: 2026/01/06 13:53:51 by nbilyj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRC = \
algo_manager.c \
check_error.c \
ft_lst_utils.c \
ft_utils.c \
insertion_sort_utils.c \
insertion_sort.c \
sort_utils_a.c \
sort_utils_ab_function.c \
sort_utils_ab.c \
sort_utils_b.c \
stack_utils.c \
	
OBJ = $(SRC:.c=.o)  

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
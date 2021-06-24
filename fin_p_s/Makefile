# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gejo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 22:44:54 by gejo              #+#    #+#              #
#    Updated: 2021/06/24 17:46:44 by gejo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c\
	  list_fn1.c\
	  list_fn2.c\
	  sort_fn1.c\
	  stack_a_cmd.c\
	  stack_b_cmd.c\
	  util_fn1.c\
	  util_fn2.c\
	  div_list.c\
	  validity_check.c\
	  split_argv.c\
	  error_fn.c

OBJ = push_swap.o\
	  list_fn1.o\
	  list_fn2.o\
	  sort_fn1.o\
	  stack_a_cmd.o\
	  stack_b_cmd.o\
	  util_fn1.o\
	  util_fn2.o\
	  div_list.o\
	  validity_check.o\
	  split_argv.o\
	  error_fn.o

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

NAME = push_swap

SRC = push_swap.c\
		list_fn.c\
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

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -g3 -fsanitize=address -o $(NAME) $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
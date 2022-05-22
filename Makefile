NAME = so_long
FLAGS =   -lmlx -framework OpenGL -framework AppKit

SRCS =	so_long.c 				\
		checker.c				\
		draw.c					\
		tools/ft_split.c 		\
		tools/get_next_line.c	\
		tools/ft_itoi.c 		\
		tools/tools.c 			\
		moves.c 				\

		

all: $(NAME)

$(NAME) : 
	@gcc $(FLAGS) $(SRCS)  -D BUFFER_SIZE=1000000 -o $(NAME) -g

fclean:
	@rm -rf $(NAME)

re: fclean all
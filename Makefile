NAME = so_long
FLAGS =   -lmlx -framework OpenGL -framework AppKit

SRCS =	checker.c			\
		draw.c				\
		ft_split.c 			\
		get_next_line.c		\
		tools.c 			\
		

all: $(NAME)

$(NAME) : 
	@gcc $(FLAGS) $(SRCS)  -D BUFFER_SIZE=1000000 -o $(NAME) -g

fclean:
	@rm -rf $(NAME)

re: fclean all
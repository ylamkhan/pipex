NAME = pipex

FLAGS = -Werror -Wextra -Wall
CC = gcc
RM = rm -rf


SRCS = fork.c\
	  libft.c\
	  libft2.c\
	  libft3.c\
	  main.c\
	  pipex.c\

all: $(NAME)
OBJ = $(SRCS:%.c=%.o)
$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(SRCS) -o $(NAME)
clean:
	 $(RM) $(OBJ)
fclean: clean
	 $(RM) $(NAME)
re:fclean all

.PHONY: all clean fclean


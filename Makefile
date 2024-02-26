NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC =  so_long.c ft_split.c get_next_line.c  get_next_line_utils.c 
	  

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

%.o: %.c so_long.h 
		$(CC) $(FLAGS) -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean
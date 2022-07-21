NAME = pokedex

CC = 	gcc

SRC =   src/main.c			\
		src/crud.c			\
		src/pokemon_depart.c		\
		src/zones.c
		
OBJ =   $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Wstrict-prototypes -std=c99 -Iinclude/ -g3 -lm

all: $(NAME)

$(NAME): $(OBJ)
		 $(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		 rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean

.PHONY: all clean fclean re

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./include
SRCS = $(wildcard src/*.c) $(wildcard utils.c) $(wildcard validate.c)
NAME = bsq

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f *.o src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

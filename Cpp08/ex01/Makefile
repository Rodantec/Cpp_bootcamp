NAME = Span

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Span.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

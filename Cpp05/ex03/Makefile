SRC = main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

NAME = Intern

OBJ = $(SRC:.cpp=.o)

FLAGS = -std=c++98 -Wall -Werror -Wextra

CC = c++

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)
	rm -f *_shrubbery

fclean	: clean
	rm -rf $(NAME)

re	: fclean all

.PHONY: all clean fclean re

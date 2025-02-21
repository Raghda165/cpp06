NAME = convert
CPPFILES = main.cpp ScalarConverter.cpp
CFLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++

all: $(NAME)

$(NAME):
	$(CPP) $(CFLAGS) $(CPPFILES) -o $(NAME)


clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

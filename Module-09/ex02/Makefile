SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

generate: $(NAME) $(BONUS_NAME)
	$(eval ARG = $(shell jot -r 3000 0 5000000))
	./PmergeMe $(ARG)

.PHONY: all clean fclean re generate
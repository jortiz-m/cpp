NAME = megaphone

SRC = megaphone.cpp

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
	@$(CPP) $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo "Compiled $(NAME)"

clean:
	rm -f $(NAME)

fclean: clean
re: fclean all
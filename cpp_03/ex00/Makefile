NAME = ClapTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled $(NAME)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Cleaned"

fclean: clean
	@rm -f $(NAME)

re: fclean all
	@echo "All ready"

.PHONY: all clean fclean re

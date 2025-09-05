NAME = ScavTrap

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp WrongAnimal/WrongAnimal.cpp Dog/Dog.cpp Cat/Cat.cpp Animal/Animal.cpp
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

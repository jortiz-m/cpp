NAME = Identify

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp A/A.cpp B/B.cpp C/C.cpp Base/Base.cpp
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled $(NAME)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)


$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@echo "Cleaned"

fclean: clean
	@rm -f $(NAME)

re: fclean all
	@echo "All ready"

.PHONY: all clean fclean re

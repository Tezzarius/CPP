#Makefile for Abstract class

# Project name
NAME = abstractClass

# Colours
GREEN = \033[0;32m
RED = \033[0;31m

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

# Source files
SRC	=	main.cpp\
		Animal.cpp\
		Cat.cpp\
		Dog.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp\
		Brain.cpp
HEAD =	Animal.hpp\
		Cat.hpp\
		Dog.hpp\
		WrongAnimal.hpp\
		WrongCat.hpp\
		Brain.hpp

OBJS = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) Compiled successfully!"

clean:
	@rm -rf $(OBJS) $(DEPS)
	@echo "$(RED)🧹 Object and dependency files removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🧹 $(NAME) removed!"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
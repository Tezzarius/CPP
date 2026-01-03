#Makefile for  Now we’re talking

# Project name
NAME = Fixed

# Colours
GREEN = \033[0;32m
RED = \033[0;31m

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

# Source files
SRC	=	main.cpp\
		Fixed.cpp
HEAD =	Fixed.hpp

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
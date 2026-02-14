#Makefile for Form up, maggots!

# Project name
NAME = Bureaucrat

# Colours
GREEN = \033[0;32m
RED = \033[0;31m

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CPPFLAGS = -I include

# Directories
SRC_DIR = src
OBJ_DIR = obj
DEP_DIR = dep

# Source files
SRC	=	main.cpp\
		Bureaucrat.cpp\
		Form.cpp

SRCS = $(addprefix $(SRC_DIR)/,$(SRC))
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:$(SRC_DIR)/%.cpp=$(DEP_DIR)/%.d)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) Compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -MT $@ -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@echo "$(RED)🧹 Object and dependency files removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🧹 $(NAME) removed!"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
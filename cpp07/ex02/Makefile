# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./

# Executable name
NAME = array_test

# Source and object files
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Header files (for dependency management)
HEADERS = Array.hpp Array.tpp

# Default target
all: $(NAME)

# Link and build executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything (including executable)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

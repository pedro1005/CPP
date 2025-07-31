# Compiler and flags
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Sources
SRCS = main.cpp

# Executable name
NAME = mutantstack

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re

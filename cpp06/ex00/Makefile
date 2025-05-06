# Compiler
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

# NAME
NAME = convert
SRCS = ScalarConverter.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = ScalarConverter.hpp

# Build the executable
all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

# Objects compilation
%.o: %.cpp $(DEPS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Clean object files and the executable
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: clean all
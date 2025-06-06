# Compiler
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
DEBUGFLAGS = -g

# NAME
NAME = iter
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = iter.hpp

# Build the executable
all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

# Debug build target
debug: CPPFLAGS += $(DEBUGFLAGS)
debug: fclean $(NAME)

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
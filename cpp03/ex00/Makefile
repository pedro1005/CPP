# Compiler
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

# Targets
NAME = claptrap
SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = ClapTrap.hpp

# Build the executable
all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Clean object files and the executable
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: clean all

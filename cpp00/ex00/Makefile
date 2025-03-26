# Compiler
CC = c++

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = megaphone

# Source files and object files
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

# Build target
all: $(TARGET)

# Compile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the object files
clean:
	rm -f $(OBJS)

# Full clean
fclean: clean
	rm -f $(TARGET)

# Rebuild
re: fclean all

.PHONY: all clean fclean re

# Compiler
CC = c++

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Target executable
TARGET = megaphone

# Build target
all: $(TARGET)

# Compile the source code with C++98 standard
$(TARGET): megaphone.cpp
	$(CC) $(CFLAGS) -o $(TARGET) megaphone.cpp

# Clean the compiled files
clean:
	rm -f $(TARGET)

# Clean and remove additional files
fclean: clean

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re

# Compiler
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

# Targets
TARGET = harl
SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = Harl.hpp

# Build the executable
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

# Clean object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild everything
re: clean all
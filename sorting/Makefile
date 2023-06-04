# Compiler 
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Source files
SRCS = main.c sorting.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = sorting

# Default target
all: $(TARGET)

# Compile source files into object files
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
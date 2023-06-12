# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Source files
SRCS = main.c binary_trees.c

# Executable name
TARGET = binary_trees

# Default target
all: $(TARGET)

#  Rule to build 
$(TARGET):$(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean the build artifacts
clean:
	rm -f $(TARGET)
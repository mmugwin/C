CC = gcc
CFLAGS = -Wall -Wextra
SRCS = main.c stacks.c
TARGET = stacks
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

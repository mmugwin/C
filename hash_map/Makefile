CC = gcc
CFLAGS = -Wall -Werror
SRCS = main.c hash_map.c
OBJS = $(SRCS:.c=.o)
TARGET = hash_map
all: $(TARGET)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS) $(TARGET)
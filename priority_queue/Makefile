CC = gcc
CFLAGS = -Wall -Werror
SRCS = main.c heap.c
OBJS = $(SRCS:.c=.o)
TARGET = min_heap

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(TARGET)
clean: 
	rm -rf $(TARGET) $(OBJS)
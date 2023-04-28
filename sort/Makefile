VERSION = 1.0

TARGET = sort
SOURCES = $(wildcard *.c ./src/*.c)
OBJS = $(patsubst %.c, %.o, $(SOURCES))

MACROS = -I_DEBUG
INCLUDES = -I./include
CFLAGS = -Wall -c

CC = gcc
OBJDUMP = objdump

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(INCLUDES) $(MACROS) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm $(TARGET) *.o ./src/*.o
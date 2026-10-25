CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude -D_DEFAULT_SOURCE
TARGET  = game-of-life
SRC     = src/functions.c src/program.c
OBJ     = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c include/functions.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean run
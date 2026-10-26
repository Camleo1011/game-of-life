CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude -D_DEFAULT_SOURCE
TARGET  = game-of-life
SRC     = src/functions.c src/program.c

all: $(TARGET)

$(TARGET): $(SRC) include/functions.h
	$(CC) $(CFLAGS) -o $@ $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean run

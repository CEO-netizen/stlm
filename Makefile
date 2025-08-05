CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/todo.c
TARGET = stlm

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

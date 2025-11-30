CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = main.c jogadores.c itens.c
OBJ = $(SRC:.c=.o)
TARGET = freefire

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

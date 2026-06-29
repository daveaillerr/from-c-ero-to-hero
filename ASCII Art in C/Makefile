CC      = gcc
CFLAGS  = -Wall -Wextra -I./include

SRC     = ./src/main.c
TARGET  = ascii_art

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

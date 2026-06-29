CC      = gcc
CFLAGS  = -Wall -Wextra

SRC     = ./src/main.c
TARGET  = pas_gen_check

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET) $(TARGET).exe

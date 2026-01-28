CC = gcc
CFLAGS = -Wall -Iinclude

ASSDIR = asset
SRC = src
SRCDIR = $(wildcard $(SRC)/*.c)
ASSET = $(wildcard $(ASSDIR)/*.png)

FINAL = ascii_printed

$(FINAL): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@ 

.PHONY: clean

clean:
	rm -f $(FINAL)
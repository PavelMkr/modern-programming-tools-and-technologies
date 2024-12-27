CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = main
SOURCE = main.c

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

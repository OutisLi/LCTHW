CC=gcc
CFLAGS=-Wall -g

TARGET=ex10

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(TARGET) $(TARGET).o

.PHONY: all clean

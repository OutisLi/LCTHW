CC=gcc
CFLAGS=-Wall -g

# 使用变量TARGET代表目标程序的名称
TARGET=ex3

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(TARGET) $(TARGET).o

.PHONY: all clean

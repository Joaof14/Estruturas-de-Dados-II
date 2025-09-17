CC=gcc
CFLAGS=-Wall -g
TARGET=questoes

SRCS=ArvoreBinaria.c Questoes.c
HDRS=ArvoreBinaria.h

all: $(TARGET)

$(TARGET): $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
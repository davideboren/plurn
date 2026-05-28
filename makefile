CC = g++

CFLAGS = -lncurses -Iinclude -Ilib

SOURCES = ./src/*.cpp

all: plurn run clean

plurn:
	$(CC) $(SOURCES) $(CFLAGS) -o plurn

run:
	./plurn

clean:
	rm plurn

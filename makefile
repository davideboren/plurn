CXX = ccache g++

CFLAGS = -g -lncurses -Ilib -Iinclude 

SOURCES = ./src/*.cpp

all: plurn run clean

plurn:
	$(CXX) $(SOURCES) $(CFLAGS) -o plurn

run:
	./plurn

clean:
	rm plurn

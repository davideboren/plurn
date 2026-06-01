CXX = ccache g++

CFLAGS = -g -Ilib -Iinclude -Wall -Wextra -std=c++20

LDFLAGS = -lncurses -lfmt

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)

TARGET = plurn

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(TARGET) 

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)


#ifndef STRUCTS_H
#define STRUCTS_H

struct Position {
   int y;
   int x;

   bool operator==(const Position& other) const {
       return y == other.y && x == other.x;
   }
};

struct Room {
    int height;
    int width;
    Position pos;
    Position center;
};

struct Tile {
    char ch;
    int color;
    bool walkable; 
    bool transparent;
    bool visible;
    bool seen;
};

#endif

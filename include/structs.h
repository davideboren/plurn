#ifndef STRUCTS_H
#define STRUCTS_H

struct Position {
   int y;
   int x;
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

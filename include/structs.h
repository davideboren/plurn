#ifndef STRUCTS_H
#define STRUCTS_H

struct Position {
   int y;
   int x;
};

struct Tile {
    char ch;
    bool walkable; 
    bool transparent;
    bool visible;
    bool seen;
};

#endif

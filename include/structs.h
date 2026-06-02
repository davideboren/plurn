#ifndef STRUCTS_H
#define STRUCTS_H

#include <rng.h>

struct Position {
   int y;
   int x;

   bool operator==(const Position& other) const {
       return y == other.y && x == other.x;
   }
};

struct Room {
    Position pos;
    int height;
    int width;
    Position center;

    Room(){}
    Room(Position p, int h, int w):
        pos(p), height(h), width(w){
        center.y = (int)(p.y + rng::rand(0, height - 1));
        center.x = (int)(p.x + rng::rand(0, width - 1));
    }
};

struct Tile {
    char ch;
    int color;
    bool walkable; 
    bool transparent;
    bool visible;
    bool seen;
};

struct Action {
    enum Type{
        Move
    };

    Type type;
};

#endif

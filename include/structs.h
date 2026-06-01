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
    Position pos;
    int height;
    int width;
    Position center;

    Room(){}
    Room(Position p, int h, int w):
        pos(p), height(h), width(w){
        center.y = (int)(p.y + height/2);
        center.x = (int)(p.x + width/2);
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

#endif

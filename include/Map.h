#ifndef MAP_H
#define MAP_H

#include <structs.h>
#include <constants.h>

class Map {
    public:
        Map();

        void digRoom(Room& room);
        Position createRoomsBSP(int h, int w, Position pos);
        Position createRoomsRandom();
        Position createRoomsSimple();
        Position createRoomsDijkstra();
        void drawWalls(Room* r);
        void connectPoints(Position c1, Position c2);
        void drawWalls();
        int charAt(int y, int x);
        void clearDMap();
        void buildDMap(Position pos);
        int getLowestNeighbor(Position pos);
        bool inMap(Position pos);

        Tile tiles[MAP_HEIGHT][MAP_WIDTH];
        int dmap[MAP_HEIGHT][MAP_WIDTH];

        static const int UNDEF_TILE = ' ';
        static const int MIN_ROOM_WIDTH = 4;
        static const int MIN_ROOM_HEIGHT = 4;
        static const int MAX_ROOM_WIDTH = 10;
        static const int MAX_ROOM_HEIGHT = 8;
        static const int MAX_ROOM_AREA = 80;
};

#endif

#ifndef MAP_H
#define MAP_H

#include <structs.h>
#include <constants.h>

class Map {
    public:
        Map();

        Room createRoom(int y, int x, int height, int width);
        void placeRoom(Room& room);
        void createRooms();
        Position createRoomsBSP(int h, int w, Position pos);
        void connectPoints(Position c1, Position c2);

        Tile tiles[MAP_HEIGHT][MAP_WIDTH];

        static const int MAX_ROOM_WIDTH = 10;
        static const int MAX_ROOM_HEIGHT = 5;
};

#endif

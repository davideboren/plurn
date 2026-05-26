#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <structs.h>
#include <constants.h>
#include <Player.h>
#include <Entity.h>

class World {
    public:
        void initMap();
        void initEntities();
        void placeRoom(int y_offset, int x_offset, int height, int width);
        void createRooms();

        void handleInput(int input);
        void tryMove(Entity& ent, Position delta);

        Tile tiles[MAP_HEIGHT][MAP_WIDTH];
        Player player;

};

#endif

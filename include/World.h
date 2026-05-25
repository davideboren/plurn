#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <structs.h>
#include <constants.h>
#include <Player.h>

class World {
    public:
        void initMap();
        void handleInput(int input);

        Tile tiles[MAP_HEIGHT][MAP_WIDTH];
        Player player;

};

#endif

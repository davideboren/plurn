#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <structs.h>
#include <constants.h>
#include <Entity.h>
#include <Map.h>
#include <Player.h>

class World {
    public:
        void initMap();
        void initEntities();

        void handleInput(int input);
        void tryMove(Entity& ent, Position delta);

        Map map;
        Player player;
};

#endif

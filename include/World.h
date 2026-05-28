#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <structs.h>
#include <Entity.h>
#include <Log.h>
#include <Map.h>
#include <Player.h>

class World {
    public:
        void initEntities();

        void handleInput(int input);
        void tryMove(Entity* ent, Position delta);
        bool walkable(Position pos);

        Map map;
        Log log;
        Player player;
        std::vector<Entity*> ents;
};

#endif

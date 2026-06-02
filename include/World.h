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
        void clearEntities();

        void handleInput(int input);
        void update();
        void tryMove(Entity* ent, Position delta);
        bool walkable(Position pos);

        Map map;
        Log log;
        Player player;
        std::vector<Entity*> ents;

        static const bool noclip = false;
};

#endif

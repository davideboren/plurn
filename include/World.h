#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <structs.h>
#include <Actor.h>
#include <Log.h>
#include <Map.h>
#include <Player.h>

class World {
    public:
        void initEntities();
        void clearEntities();

        void handleInput(int input);
        void update();
        void tryMove(Actor* ent, Position delta);
        bool walkable(Position pos);

        Map map;
        Log log;
        Player player;
        std::vector<Actor*> ents;

        static const bool noclip = false;
};

#endif

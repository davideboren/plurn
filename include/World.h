#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <structs.h>
#include <Actor.h>
#include <Action.h>
#include <Log.h>
#include <Map.h>
#include <Player.h>

class World {
    public:
        void initEntities();
        void clearEntities();

        void handleInput(int input);
        void update();
        void tryAction(Actor* actor, Action action);
        void tryMove(Actor* ent, Position delta);
        Actor* actorAt(Position pos);
        bool walkable(Position pos);
        void interact(Actor* src_actor, Actor* dest_actor);

        Map map;
        Log log;
        Player player;
        std::vector<Actor*> actors;

        static const bool noclip = false;
};

#endif

#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include <structs.h>
#include <Actor.h>
#include <Action.h>
#include <Feed.h>
#include <Map.h>
#include <Player.h>
#include <WorldWiz.h>

class World {
    public:
        void initEntities();
        void clearEntities();

        void handleInput(int input);
        void update();
        void tryAction(Actor* actor, Action action);

        Map map;
        Feed feed;
        Player player;
        std::vector<Actor*> actors;
        WorldWiz wiz = WorldWiz(&map, &actors, &feed);

        static const bool noclip = false;
};

#endif

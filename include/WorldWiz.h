#ifndef WORLDWIZ_H
#define WORLDWIZ_H

#include <vector>

#include <structs.h>

#include <Map.h>

class Actor;

class WorldWiz {
    private:
        Map* map;
        std::vector<Actor*>* actors;

    public:
        WorldWiz(Map* map, std::vector<Actor*>* actors):
            map(map), actors(actors){};

        Actor* actorAt(Position pos);
        bool walkable(Position pos);
};

#endif

#ifndef WORLDWIZ_H
#define WORLDWIZ_H

#include <vector>
#include <string>

#include <structs.h>

#include <Map.h>
#include <Feed.h>

class Actor;

class WorldWiz {
    private:
        Map* map;
        std::vector<Actor*>* actors;

    public:
        Feed* feed;

        WorldWiz(Map* map, std::vector<Actor*>* actors, Feed* feed):
            map(map), actors(actors), feed(feed){};

        Actor* actorAt(Position pos);
        bool walkable(Position pos);
};

#endif

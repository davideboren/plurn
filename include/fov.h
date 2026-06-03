#pragma once

#include <vector>

#include <structs.h>
#include <Actor.h>
#include <Map.h>

namespace fov{
    //FOV
    void makeFOV(Map* map, std::vector<Actor*> *actors, Actor* player);
    void clearFOV(Map* map, std::vector<Actor*> *actors, Actor* player);
    bool lineOfSight(Map* map, Position origin, Position target);

    // Helpers
    int getDistance(Position p1, Position p2);
    bool isInMap(int y, int x);
    int getSign(int a);
}

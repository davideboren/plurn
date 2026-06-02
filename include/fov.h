#pragma once

#include <vector>

#include <structs.h>
#include <Entity.h>
#include <Map.h>

namespace fov{
    //FOV
    void makeFOV(Map* map, std::vector<Entity*> *ents, Entity* player);
    void clearFOV(Map* map, std::vector<Entity*> *ents, Entity* player);
    bool lineOfSight(Map* map, Position origin, Position target);

    // Helpers
    int getDistance(Position p1, Position p2);
    bool isInMap(int y, int x);
    int getSign(int a);
}

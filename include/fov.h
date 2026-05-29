#pragma once

#include <structs.h>
#include <Entity.h>
#include <Map.h>

namespace fov{
    //FOV
    void makeFOV(Map* map, Entity* player);
    void clearFOV(Map* map, Entity* player);
    bool lineOfSight(Map* map, Position origin, Position target);

    // Helpers
    int getDistance(Position p1, Position p2);
    bool isInMap(int y, int x);
    int getSign(int a);
}

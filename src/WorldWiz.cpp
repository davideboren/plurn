#include <WorldWiz.h>

#include <string>

#include <Actor.h>
#include <Logger.h>

Actor* WorldWiz::actorAt(Position pos){
    Actor* out = nullptr;
    for(Actor* actor : *actors){
        if(actor->pos == pos){
            out = actor;
            return out;
        }
    }
    return out;
}

bool WorldWiz::walkable(Position pos){
    if(pos.y >= MAP_HEIGHT || pos.x >= MAP_WIDTH){
        return false;
    }

    Actor* act = actorAt(pos);
    if(act && act->blocks){
        return false;
    }
    if(map->tiles[pos.y][pos.x].walkable){
        return true;
    }

    return false;
}

Position WorldWiz::rollDown(Position pos){
    Position low_vec = {0,0};
    for(int y = -1; y <= 1; y++){
        for(int x = -1; x <= 1; x++){
            if(map->dmap[pos.y + y][pos.x + x] < map->dmap[pos.y + low_vec.y][pos.x + low_vec.x]){
               low_vec = {y, x};
           }
        }
    }

    return {low_vec.y, low_vec.x};
}

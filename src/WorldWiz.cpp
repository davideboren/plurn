#include <WorldWiz.h>

#include <Actor.h>

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

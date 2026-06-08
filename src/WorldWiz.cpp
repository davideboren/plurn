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
    return false;
}

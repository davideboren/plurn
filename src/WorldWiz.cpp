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
    Position low_pos = pos;
    for(int y = pos.y - 1; y < pos.y + 1; y++){
        for(int x = pos.x - 1; x < pos.x + 1; x++){

           Logger::log(fmt::format("Low: {}, Cur: {}",
                map->dmap[low_pos.y][low_pos.x],
                map->dmap[y][x]));
           if(map->dmap[y][x] < map->dmap[low_pos.y][low_pos.x]){
               low_pos = {y, x};
           }
        }
    }

    return low_pos;
}

#include <World.h>

#include <random>

#include <structs.h>
#include <constants.h>
#include <Entity.h>
#include <ncurses.h>

void World::initEntities(){
    player.initPlayer(7, 70);
    ents.push_back(&player);

    Entity* goblin = new Entity;
    goblin->pos = {5, 71};
    goblin->ch = 'g';
    goblin->color = COLOR_PAIR(MONSTER_COLOR);
    ents.push_back(goblin);
}

void World::handleInput(int input){
    switch(input){
    case 'h':
        tryMove(&player, {0, -1});
        break;
    case 'j':
        tryMove(&player, {1, 0});
        break;
    case 'k':
        tryMove(&player, {-1, 0});
        break;
    case 'l':
        tryMove(&player, {0, 1});
        break;
    default:
        break;
    }
}

void World::tryMove(Entity* ent, Position delta){
    Position new_pos = {ent->pos.y + delta.y, ent->pos.x + delta.x};

    if(walkable(new_pos)){
        ent->pos.y += delta.y;
        ent->pos.x += delta.x;
    } else {
        log.push("Can't walk through that.");
    }
}

bool World::walkable(Position pos){
    for(Entity* ent : ents){
        if(ent->pos == pos){
            return false;
        }
    }
    if(map.tiles[pos.y][pos.x].walkable){
        return true;
    }

    return false;
}

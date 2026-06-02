#include <World.h>

#include <ncurses.h>
#include <random>

#include <structs.h>
#include <constants.h>
#include <fov.h>
#include <rng.h>

#include <Actor.h>
#include <Monster.h>
#include <Logger.h>

void World::initEntities(){
    player.initPlayer();
    ents.push_back(&player);


    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            if(fov::lineOfSight(&map, player.pos, {y, x})){
                continue;
            }
            if(map.charAt(y, x) == '.' && !rng::rand(0,63)){
                Monster* goblin = new Monster;
                goblin->pos = {y, x};
                goblin->ch = 'g';
                goblin->color = COLOR_PAIR(MONSTER_COLOR);
                ents.push_back(goblin);
            }
        }
    }
}

void World::clearEntities(){
    for(Actor* ent : ents){
        if(ent != &player){
            delete ent;
        }
    }
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

void World::update(){
    fov::makeFOV(&map, &ents, &player);
}

void World::tryMove(Actor* ent, Position delta){
    fov::clearFOV(&map, &ents, &player);
    Position new_pos = {ent->pos.y + delta.y, ent->pos.x + delta.x};

    if(walkable(new_pos)){
        ent->pos.y += delta.y;
        ent->pos.x += delta.x;
    } else {
        log.push("Can't walk through that.");
    }
}

bool World::walkable(Position pos){
    if(pos.y >= MAP_HEIGHT || pos.x >= MAP_WIDTH){
        return false;
    } else if(noclip){
        return true;
    }

    for(Actor* ent : ents){
        if(ent->pos == pos){
            return false;
        }
    }
    if(map.tiles[pos.y][pos.x].walkable){
        return true;
    }

    return false;
}

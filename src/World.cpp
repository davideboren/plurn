#include <World.h>

#include <ncurses.h>
#include <random>

#include <structs.h>
#include <constants.h>
#include <fov.h>
#include <rng.h>

#include <Actor.h>
#include <Action.h>
#include <Logger.h>

void World::initEntities(){
    player.initPlayer();
    actors.push_back(&player);


    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            if(fov::lineOfSight(&map, player.pos, {y, x})){
                continue;
            }
            if(map.charAt(y, x) == '.' && !rng::rand(0,31)){
                Actor* monster = new Actor;
                monster->pos = {y, x};
                monster->ch = 's';
                monster->color = COLOR_PAIR(MONSTER_COLOR);
                actors.push_back(monster);
            }
        }
    }
}

void World::clearEntities(){
    for(Actor* actor : actors){
        if(actor != &player){
            delete actor;
        }
    }
}

void World::handleInput(int input){
    switch(input){
        case 'h':
            player.setMove(0, -1);
            break;
        case 'j':
            player.setMove(1, 0);
            break;
        case 'k':
            player.setMove(-1, 0);
            break;
        case 'l':
            player.setMove(0, 1);
            break;
        case 'b':
            player.setMove(1, -1);
            break;
        case 'u':
            player.setMove(-1, 1);
            break;
        case 'n':
            player.setMove(1, 1);
            break;
        case 'y':
            player.setMove(-1, -1);
            break;
        default:
            break;
    }
}

void World::update(){
    fov::clearFOV(&map, &actors, &player);

    for(Actor* actor : actors){
        if(actor != &player){
            actor->update();
        }
        tryAction(actor, actor->getAction());
    }

    fov::makeFOV(&map, &actors, &player);
}

void World::tryAction(Actor* actor, Action action){
    if(action.type == Action::MOVE){
        tryMove(actor, {action.dy, action.dx});
    }
}

void World::tryMove(Actor* actor, Position delta){
    Position new_pos = {actor->pos.y + delta.y, actor->pos.x + delta.x};
    if(walkable(new_pos)){
        actor->pos.y += delta.y;
        actor->pos.x += delta.x;
    } else {
        Actor* obstacle = actorAt(new_pos);
        if(obstacle){
            interact(actor, obstacle);
        } else if(actor == &player){
            log.push("Can't walk through that.");
        }
    }
}

Actor* World::actorAt(Position pos){
    for(Actor* actor : actors){
        if(actor->pos == pos){
            return actor;
        }
    }
    return nullptr;
}

bool World::walkable(Position pos){
    if(pos.y >= MAP_HEIGHT || pos.x >= MAP_WIDTH){
        return false;
    } else if(noclip){
        return true;
    }
    for(Actor* actor : actors){
        if(actor->pos == pos){
            return false;
        }
    }
    if(map.tiles[pos.y][pos.x].walkable){
        return true;
    }
    return false;
}

void World::interact(Actor* src_actor, Actor* dest_actor){
    if(src_actor == &player){
        log.push("Bumped into somebody.");
    }
}

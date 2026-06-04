#include <World.h>

#include <ncurses.h>
#include <random>
#include <fmt/core.h>

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
                Actor* monster = new Actor();
                monster->name = "slimoid";
                monster->pos = {y, x};
                monster->ch = 's';
                monster->stats.max_hp = 3;
                monster->stats.cur_hp = 3;
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
    switch(action.type){
        case Action::WAIT:
            break;
        case Action::MOVE:
            tryMove(actor, {action.dy, action.dx});
            break;
        case Action::ATTACK:
           if(actor->target && fov::getDistance(actor->pos, actor->target->pos) <= 1){
               attack(actor, actor->target);
           }
    }
}

void World::tryMove(Actor* actor, Position delta){
    Position new_pos = {actor->pos.y + delta.y, actor->pos.x + delta.x};

    Actor* obstacle = actorAt(new_pos);
    if(obstacle && obstacle->blocks){
        interact(actor, obstacle);
    }
    else if(walkable(new_pos)){
        actor->pos.y += delta.y;
        actor->pos.x += delta.x;
    } else if(actor == &player){
        feed.push("Can't walk through that.");
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
    Actor* act = actorAt(pos);
    if(act && act->blocks){
        return false;
    }
    if(map.tiles[pos.y][pos.x].walkable){
        return true;
    }
    return false;
}

void World::interact(Actor* src_actor, Actor* dest_actor){
    if(src_actor == &player){
        attack(src_actor, dest_actor);
    }
}

void World::attack(Actor* src_actor, Actor* dest_actor){
    if(src_actor == &player){
        feed.push(fmt::format("You pound the {} with your fist.", dest_actor->name));
    } else {
        feed.push(fmt::format("{} attacks {}!", src_actor->name, dest_actor->name));
    }
    dest_actor->target = src_actor;
    dest_actor->stats.cur_hp -= rng::rand(1, src_actor->stats.atk);
    if(dest_actor->stats.cur_hp <= 0){
        feed.push(fmt::format("{} killed {}.", src_actor->name, dest_actor->name));
        dest_actor->die();
        src_actor->target = nullptr;
    }
}


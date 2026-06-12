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
#include <WorldWiz.h>

#include <MonsterAI.h>

void World::initEntities(){
    player.initPlayer(&wiz);
    actors.push_back(&player);


    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            if(y == player.pos.y && x == player.pos.x){
                continue;
            }
            if(map.charAt(y, x) == '.' && !rng::rand(0,15)){
                Actor* monster = new Actor(&wiz);
                monster->name = "slimoid";
                monster->pos = {y, x};
                monster->ch = 's';
                monster->color = COLOR_PAIR(MONSTER_COLOR);
                monster->destructible = new Destructible(3, 3, "dead slimoid");
                monster->attacker = new Attacker(&wiz, 1);
                monster->mover = new Mover();
                monster->ai = new MonsterAI(&wiz);
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
    player.ai->handleInput(&player, input);
}

void World::update(){
    fov::clearFOV(&map, &actors, &player);

    for(Actor* actor : actors){
        if(actor == &player){
            actor->ai->update(actor);
            actor->ai->tryAction(actor);
            map.buildDMap(player.pos);
        } else {
            actor->ai->update(actor);
            actor->ai->tryAction(actor);
        }
    }

    feed.push_buffer();

    fov::makeFOV(&map, &actors, &player);
}


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
                monster->attacker = new Attacker(1);
                monster->mover = new Mover();
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
        actor->update();
        tryAction(actor, actor->getAction());
    }

    fov::makeFOV(&map, &actors, &player);
}

void World::tryAction(Actor* actor, Action action){
    switch(action.type){
        case Action::WAIT:
            break;
        case Action::MOVE:
            if(actor->mover){
                actor->mover->tryMove(actor, &wiz, {action.dy, action.dx});
            }
            break;
        case Action::ATTACK:
           if(fov::getDistance(actor->pos, actor->attacker->target->pos) <= 1){
               feed.push(fmt::format("{} attacks {}!", actor->name, actor->attacker->target->name));
               actor->attacker->attack(actor, actor->attacker->target);
           }
    }
}


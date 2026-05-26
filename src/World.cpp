#include <World.h>

#include <random>

#include <structs.h>
#include <constants.h>
#include <Entity.h>
#include <ncurses.h>

void World::initMap(){
    map.initMap();
}

void World::initEntities(){
    player.pos = {7, 85};
}

void World::handleInput(int input){
    switch(input){
    case 'h':
        tryMove(player, {0, -1});
        break;
    case 'j':
        tryMove(player, {1, 0});
        break;
    case 'k':
        tryMove(player, {-1, 0});
        break;
    case 'l':
        tryMove(player, {0, 1});
        break;
    default:
        break;
    }
}

void World::tryMove(Entity& ent, Position delta){
    if(map.tiles[ent.pos.y + delta.y][ent.pos.x + delta.x].walkable){
        ent.pos.y += delta.y;
        ent.pos.x += delta.x;
    }
}

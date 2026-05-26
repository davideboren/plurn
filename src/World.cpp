#include <World.h>
#include <structs.h>
#include <constants.h>
#include <Entity.h>
#include <random>

void World::initMap(){
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            tiles[y][x].ch = '#';
            tiles[y][x].walkable = false;
            tiles[y][x].transparent = false;
            tiles[y][x].visible = false;
            tiles[y][x].seen = false;
        }
    }

    placeRoom(10, 30, 10, 30);
}

void World::initEntities(){
    player.pos = {15, 35};
}

void World::placeRoom(int y_offset, int x_offset, int height, int width){
   for(int y = y_offset; y < y_offset + height; y++){
        for(int x = x_offset; x < x_offset + width; x++){
            tiles[y][x].ch = '.';
            tiles[y][x].walkable = true;
            tiles[y][x].transparent = true;
        }
   }
}

void World::createRooms(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 1000);

    int n_rooms = distr(gen) % 5 + 7;

    for(int n = 0; n < n_rooms; n++){
       int width = distr(gen) % 20 + 10;
       int height = distr(gen) % 10 + 10;
    }

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
    if(tiles[ent.pos.y + delta.y][ent.pos.x + delta.x].walkable){
        ent.pos.y += delta.y;
        ent.pos.x += delta.x;
    }
}

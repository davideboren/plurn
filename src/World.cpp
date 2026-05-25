#include <World.h>
#include <constants.h>

void World::initMap(){
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            tiles[y][x].ch = '.';
            tiles[y][x].walkable = false;
            tiles[y][x].transparent = false;
            tiles[y][x].visible = false;
            tiles[y][x].seen = false;
        }
    }

}

void World::handleInput(int input){
    switch(input){
    case 'h':
        player.pos.x--;
        break;
    case 'j':
        player.pos.y++;
        break;
    case 'k':
        player.pos.y--;
        break;
    case 'l':
        player.pos.x++;
        break;
    default:
        break;
    }
}

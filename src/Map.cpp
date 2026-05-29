#include <Map.h>

#include <random>
#include <ncurses.h>

#include <structs.h>
#include <constants.h>

Map::Map(){
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            tiles[y][x].ch = ' ';
            tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
            tiles[y][x].walkable = false;
            tiles[y][x].transparent = false;
            tiles[y][x].visible = false;
            tiles[y][x].seen = false;
        }
    }
}

Room Map::createRoom(int y, int x, int height, int width){
    Room new_room;

    new_room.pos.y = y;
    new_room.pos.x = x;
    new_room.height = height;
    new_room.width = width;
    new_room.center.y = y + (int)(height/2);
    new_room.center.x = x + (int)(width/2);

    return new_room;
}

void Map::placeRoom(Room& room){
    for(int y = room.pos.y; y < room.pos.y + room.height; y++){
        tiles[y][room.pos.x].ch = '|';
        tiles[y][room.pos.x + room.width].ch = '|';
    }
    for(int x = room.pos.x; x < room.pos.x + room.width + 1; x++){
        tiles[room.pos.y][x].ch = '-';
        tiles[room.pos.y + room.height][x].ch = '-';
    }

    //tiles[room.pos.y][room.pos.x].ch = 'x';
    //tiles[room.pos.y + room.height][room.pos.x].ch = 'x';
    //tiles[room.pos.y][room.pos.x + room.width].ch = 'x';
    //tiles[room.pos.y + room.height][room.pos.x + room.width].ch = 'x';

    for(int y = room.pos.y + 1; y < room.pos.y + room.height; y++){
        for(int x = room.pos.x + 1; x < room.pos.x + room.width; x++){
            tiles[y][x].ch = '.';
            tiles[y][x].walkable = true;
            tiles[y][x].transparent = true;
        }
   }
}

/*
void Map::createRooms(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 1000);

    int n_rooms = distr(gen) % 5 + 7;

    for(int n = 0; n < n_rooms; n++){
       int width = distr(gen) % 20 + 10;
       int height = distr(gen) % 10 + 10;
    }

}*/

void Map::connectPoints(Position c1, Position c2){
    Position temp;
    temp.y = c1.y;
    temp.x = c1.x;

    while(true){
        if(abs((temp.x - 1) - c2.x) < abs(temp.x - c2.x)){
            temp.x--;
        } else if(abs((temp.x + 1) - c2.x) < abs(temp.x - c2.x)){
            temp.x++;
        } else if(abs((temp.y + 1) - c2.y) < abs(temp.y - c2.y)){
            temp.y++;
        } else if(abs((temp.y - 1) - c2.y) < abs(temp.y - c2.y)){
            temp.y--;
        } else{
            break;
        }

        Tile cur_tile = tiles[temp.y][temp.x];

        if(cur_tile.ch == ' '){
            tiles[temp.y][temp.x].walkable = true;
            tiles[temp.y][temp.x].transparent = true;
            tiles[temp.y][temp.x].ch = '#';
        } else if(cur_tile.ch == '|' || cur_tile.ch == '-'){
            tiles[temp.y][temp.x].ch = '+';
            tiles[temp.y][temp.x].transparent = false;
            tiles[temp.y][temp.x].walkable = true;
            tiles[temp.y][temp.x].color = COLOR_PAIR(PLAYER_COLOR);
        } else {
            tiles[temp.y][temp.x].ch = '.';
            tiles[temp.y][temp.x].walkable = true;
            tiles[temp.y][temp.x].transparent = true;
        }
    }

}


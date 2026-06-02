#include <Map.h>

#include <ncurses.h>
#include <fmt/core.h>

#include <structs.h>
#include <constants.h>
#include <rng.h>
#include <Logger.h>

Map::Map(){
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            tiles[y][x].ch = UNDEF_TILE;
            tiles[y][x].color = COLOR_PAIR(VISIBLE_COLOR);
            tiles[y][x].walkable = false;
            tiles[y][x].transparent = false;
            tiles[y][x].visible = false;
            tiles[y][x].seen = false;
        }
    }
}

void Map::digRoom(Room& room){
    for(int y = room.pos.y; y < room.pos.y + room.height; y++){
        for(int x = room.pos.x; x < room.pos.x + room.width; x++){
            tiles[y][x].ch = '.';
            tiles[y][x].walkable = true;
            tiles[y][x].transparent = true;
        }
    }

}

Position Map::createRoomsBSP(int h, int w, Position pos){
    if(h * w < MAX_ROOM_AREA){
        //Room r = createRoom(pos.y, pos.x, h-2, w-2);
        Room r({pos.y, pos.x}, h-2, w-2);
        digRoom(r);
        return r.center;
    } else {
        Position new_pos_a = {pos.y, pos.x};
        Position new_pos_b;

        int y_split = rng::rand(0,1);
        if(y_split){
            new_pos_b = {pos.y + h/2, pos.x};
            connectPoints(createRoomsBSP(h/2, w, new_pos_a), createRoomsBSP(h/2, w, new_pos_b));
        } else {
            new_pos_b = {pos.y, pos.x + w/2};
            connectPoints(createRoomsBSP(h, w/2, new_pos_a), createRoomsBSP(h, w/2, new_pos_b));
        }
    }
}

Position Map::createRoomsRandom(){
    int n_rooms = rng::rand(0, 5) + 7;

    Position prev_center = {-1, -1};
    Position start;
    for(int i = 0; i < n_rooms; i++){
        int y = rng::rand(1, MAP_HEIGHT - MAX_ROOM_HEIGHT - 1); 
        int x = rng::rand(1, MAP_WIDTH - MAX_ROOM_WIDTH - 1); 
        int h = rng::rand(3, MAX_ROOM_HEIGHT);
        int w = rng::rand(3, MAX_ROOM_WIDTH);
        Room r({y, x}, h, w);
        digRoom(r);

        if(prev_center.y != -1){
            drawWalls();
            connectPoints(r.center, prev_center);
        } else {
            start = r.center;
        }

        prev_center = r.center;
    }

    return start;
}

Position Map::createRoomsSimple(){
    int sector_rows = 3;
    int sector_cols = 4;
    int num_sectors = sector_rows * sector_cols;

    Position centers[num_sectors];
    int centers_idx = 0;

    for(int y = 0; y < sector_rows; y++){
        for(int x = 0; x < sector_cols; x++){
            int sector_height = MAP_HEIGHT / sector_rows;
            int sector_width = MAP_WIDTH / sector_cols;

            int room_height = rng::rand(3, sector_height - 4);
            int room_width = rng::rand(3, sector_width - 2);
            int room_y = y * sector_height + rng::rand(1, sector_height - room_height - 1);
            int room_x = x * sector_width + rng::rand(1, sector_width - room_width - 1);

            //Logger::log(fmt::format("Making room: ({}, {}), {}x{}", room_y, room_x, room_height, room_width));

            Room r({room_y, room_x}, room_height, room_width);
            digRoom(r);
            centers[centers_idx] = r.center;
            centers_idx++;
        }
    }

    drawWalls();

    for(int i = 1; i < num_sectors; i++){
        connectPoints(centers[i], centers[i-1]);
    }

    return centers[rng::rand(0,num_sectors - 1)];
}

void Map::connectPoints(Position c1, Position c2){
    //Logger::log(fmt::format("Connecting ({}, {})->({}, {})", c1.y, c1.x, c2.y, c2.x));
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

        if(cur_tile.ch == UNDEF_TILE){
            tiles[temp.y][temp.x].walkable = true;
            tiles[temp.y][temp.x].transparent = true;
            tiles[temp.y][temp.x].ch = '#';
        } else if(cur_tile.ch == '|' || cur_tile.ch == '-'){
            tiles[temp.y][temp.x].walkable = true;
            tiles[temp.y][temp.x].transparent = false;
            tiles[temp.y][temp.x].ch = '+';
            tiles[temp.y][temp.x].color = COLOR_PAIR(PLAYER_COLOR);
        }
    }
}

void Map::drawWalls(){
    for(int y = 0; y < MAP_HEIGHT; y++){
        for(int x = 0; x < MAP_WIDTH; x++){
            if(tiles[y][x].ch == UNDEF_TILE){
                if(charAt(y-1,x) == '.' || charAt(y+1,x) == '.'){
                    tiles[y][x].ch = '-';
                } else if(charAt(y, x+1) == '.' || charAt(y,x-1) == '.'){
                    tiles[y][x].ch = '|';
                }
            }
        }
    }
}

int Map::charAt(int y, int x){
    if ((0 <= y && y < MAP_HEIGHT) && (0 <= x && x < MAP_WIDTH)){
        return tiles[y][x].ch;
    }

    return '?';
}


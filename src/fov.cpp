#include <fov.h>

#include <structs.h>
#include <Entity.h>

#include <cmath>

namespace fov{

    void makeFOV(Map* map, Entity* player){
        int y, x, distance;

        int RADIUS = 12;
        Position target;

        map->tiles[player->pos.y][player->pos.x].visible = true;
        map->tiles[player->pos.y][player->pos.x].seen = true;

        for(y = player->pos.y - RADIUS; y < player->pos.y + RADIUS; y++){
            for(x = player->pos.x - RADIUS; x < player->pos.x + RADIUS; x++){
                target.y = y;
                target.x = x;
                distance = getDistance(player->pos, target);

                int terrain_radius = RADIUS;
                if(map->tiles[y][x].ch == '#'){
                    terrain_radius = 2;
                }

                if(distance < terrain_radius){
                    if(isInMap(y, x) && lineOfSight(map, player->pos, target)){
                        map->tiles[y][x].visible = true;
                        map->tiles[y][x].seen = true;
                    }

                }
            }
        }
    }
 
    void clearFOV(Map* map, Entity* player){
        int y, x;
        int RADIUS = 12;

        for(y = player->pos.y - RADIUS; y < player->pos.y + RADIUS; y++){
            for(x = player->pos.x - RADIUS; x < player->pos.x + RADIUS; x++){
                if(isInMap(y, x)){
                    map->tiles[y][x].visible = false;
                }
            }
        }
    }

    int getDistance(Position p1, Position p2){
        double dy, dx;
        int dist;
        dx = p2.x - p1.x;
        dy = p2.y - p1.y;
        dist= floor(sqrt((dx * dx) + (dy * dy)));

        return dist;
    }

    bool isInMap(int y, int x){
        if ((0 < y && y < MAP_HEIGHT - 1) && (0 < x && x < MAP_WIDTH - 1)){
            return true;
        }
        
        return false;
    }


    bool lineOfSight(Map* map, Position origin, Position target){
        int t, x, y, abs_delta_x, abs_delta_y, sign_x, sign_y, delta_x, delta_y;

        delta_x = origin.x - target.x;
        delta_y = origin.y - target.y;

        abs_delta_x = abs(delta_x);
        abs_delta_y = abs(delta_y);

        sign_x = getSign(delta_x);
        sign_y = getSign(delta_y);

        x = target.x;
        y = target.y;

        if(abs_delta_x > abs_delta_y){
            t = abs_delta_y * 2 - abs_delta_x;

            do{
                if(t >= 0){
                    y += sign_y;
                    t -= abs_delta_x * 2;
                }

                x += sign_x;
                t += abs_delta_y * 2;

                if(x == origin.x && y == origin.y){
                    return true;
                }
            }
            while (map->tiles[y][x].transparent);

            return false;
        }
        else {
            t = abs_delta_x * 2 - abs_delta_y;
            do{
                if(t >= 0){
                    x += sign_x;
                    t -= abs_delta_y * 2;
                }

                y += sign_y;
                t += abs_delta_x * 2;

                if(x == origin.x && y == origin.y){
                    return true;
                }
            }
            while(map->tiles[y][x].transparent);

            return false;
        }
    }

    int getSign(int a){
        return (a < 0) ? -1 : 1;
    }

}

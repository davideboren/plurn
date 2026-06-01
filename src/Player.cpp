#include <Player.h>

#include <ncurses.h>

#include <constants.h>
#include <Entity.h>

void Player::initPlayer(int y, int x){
    ch = '@';
    color = COLOR_PAIR(PLAYER_COLOR);
    //pos.y = y;
    //pos.x = x;
}


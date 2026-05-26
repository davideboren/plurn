#include <Player.h>

#include <ncurses.h>

#include <constants.h>
#include <Entity.h>

Player::Player(){
   ch = '@';
   color = COLOR_PAIR(PLAYER_COLOR);
}

void Player::initPlayer(int y, int x){
    pos.y = y;
    pos.x = x;
}


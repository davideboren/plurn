#include <Player.h>

#include <ncurses.h>

#include <constants.h>
#include <Entity.h>

void Player::initPlayer(){
    ch = '@';
    color = COLOR_PAIR(PLAYER_COLOR);
    visible = true;
}


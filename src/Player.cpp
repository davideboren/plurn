#include <Player.h>

#include <ncurses.h>

#include <constants.h>
#include <Actor.h>

void Player::initPlayer(){
    ch = '@';
    color = COLOR_PAIR(PLAYER_COLOR);
    visible = true;
}


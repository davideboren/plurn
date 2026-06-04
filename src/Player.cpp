#include <Player.h>

#include <ncurses.h>

#include <constants.h>
#include <Actor.h>
#include <Action.h>

void Player::initPlayer(){
    name = "Hero";
    ch = '@';
    color = COLOR_PAIR(PLAYER_COLOR);
    visible = true;
    stats.atk = 2;
    stats.cur_hp = 9;
    stats.max_hp = 9;
}

void Player::setMove(int dy, int dx){
    cur_action.type = Action::MOVE;
    cur_action.dy = dy;
    cur_action.dx = dx;
}


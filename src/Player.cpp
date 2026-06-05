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
    destructible = new Destructible(9, 9, "Dead guy");
    attacker = new Attacker(2);
}

void Player::update(){

}

void Player::setMove(int dy, int dx){
    if(alive){
        cur_action.type = Action::MOVE;
        cur_action.dy = dy;
        cur_action.dx = dx;
    }
}


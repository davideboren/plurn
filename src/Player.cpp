#include <Player.h>

#include <ncurses.h>

#include <constants.h>

#include <Map.h>
#include <Actor.h>
#include <Action.h>
#include <AI.h>
#include <PlayerAI.h>

void Player::initPlayer(WorldWiz* wwiz){
    name = "Hero";
    ch = '@';
    color = COLOR_PAIR(PLAYER_COLOR);
    visible = true;
    wiz = wwiz;

    destructible = new Destructible(9, 9, "Dead guy");
    attacker = new Attacker(wiz, 2);
    mover = new Mover();
    ai = new PlayerAI();
}

void Player::update(){
}

void Player::setMove(int dy, int dx){
    if(!destructible->isDead()){
        cur_action.type = Action::MOVE;
        cur_action.dy = dy;
        cur_action.dx = dx;
    }
}


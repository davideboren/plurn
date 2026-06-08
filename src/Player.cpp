#include <Player.h>

#include <ncurses.h>

#include <constants.h>

#include <Map.h>
#include <Actor.h>
#include <Action.h>

void Player::initPlayer(WorldWiz* wwiz, Map* map, std::vector<Actor*>* actors){
    name = "Hero";
    ch = '@';
    color = COLOR_PAIR(PLAYER_COLOR);
    visible = true;
    wiz = wwiz;

    destructible = new Destructible(9, 9, "Dead guy");
    attacker = new Attacker(2);
    mover = new Mover(map, actors);
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


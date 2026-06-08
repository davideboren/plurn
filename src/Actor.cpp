#include <Actor.h>

#include <Action.h>
#include <Logger.h>
#include <fmt/core.h>
#include <rng.h>

void Actor::update(){
    if(!destructible->isDead()){
        if(attacker && attacker->target){
            cur_action.type = Action::ATTACK;
        } else if(!rng::rand(0,2)){
            cur_action.type = Action::MOVE;
            cur_action.dy = rng::rand(-1,1);
            cur_action.dx = rng::rand(-1,1);
        } else {
            cur_action.type = Action::WAIT;
        }
    }
}

Action Actor::getAction(){
    Action out = cur_action;
    cur_action = Action(Action::WAIT);

    return out;
}

void Actor::setAction(Action action){
    cur_action = action;
}

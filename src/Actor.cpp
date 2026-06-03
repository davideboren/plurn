#include <Actor.h>

#include <Action.h>
#include <Logger.h>
#include <fmt/core.h>
#include <rng.h>

Actor::Actor(){
}

void Actor::update(){
    cur_action.type = Action::MOVE;
    cur_action.dy = rng::rand(-1,1);
    cur_action.dx = rng::rand(-1,1);
}

Action Actor::getAction(){
    Action out = cur_action;
    cur_action = Action(Action::WAIT);

    return out;
}

void Actor::setAction(Action action){
    cur_action = action;
}

#include <MonsterAI.h>

#include <rng.h>
#include <Action.h>

void MonsterAI::handleInput(Actor* owner, int input){

}

void MonsterAI::update(Actor* owner){
    if(!owner->destructible->isDead()){
        if(owner->attacker && owner->attacker->target){
            cur_action.type = Action::ATTACK;
        } else if(!rng::rand(0,2)){
            cur_action.type = Action::MOVE;
            cur_action.dy = rng::rand(-1,1);
            cur_action.dx = rng::rand(-1,1);
        } else {
            cur_action.type = Action::WAIT;
        }
    } else {
        cur_action.type = Action::WAIT;
    }
}

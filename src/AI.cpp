#include <fov.h>

#include <AI.h>

void AI::tryAction(Actor* owner){
    switch(cur_action.type){
        case Action::WAIT:
            break;
        case Action::MOVE:
            if(owner->mover){
                owner->mover->tryMove(owner, wiz, {cur_action.dy, cur_action.dx});
            }
            break;
        case Action::ATTACK:
            if(owner->attacker && owner->attacker->target){
                if(fov::getDistance(owner->pos, owner->attacker->target->pos) <= 1){
                    owner->attacker->attack(owner, owner->attacker->target);
                }
            }
            break;
        default:
            break;
    }
}

void AI::setMove(Actor* owner, int dy, int dx){
    cur_action.type = Action::MOVE;
    cur_action.dy = dy;
    cur_action.dx = dx;
}

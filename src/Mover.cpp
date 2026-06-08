#include <plurn.h>

void Mover::tryMove(Actor* owner){
    Position new_pos = {owner->pos.y + dy, owner->pos.x + dx};

    Actor* obstacle = nullptr;

    if(obstacle && obstacle->blocks){
        if(owner->attacker && obstacle->destructible && owner->name != obstacle->name){
            owner->attacker->attack(owner, obstacle);
        }
    }
}

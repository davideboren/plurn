#include <plurn.h>

void Mover::tryMove(Actor* owner, WorldWiz* wiz){
    Position new_pos = {owner->pos.y + dy, owner->pos.x + dx};

    Actor* obstacle = wiz->actorAt(new_pos);

    if(obstacle && obstacle->blocks){
        if(owner->attacker && obstacle->destructible && owner->name != obstacle->name){
            owner->attacker->attack(owner, obstacle);
        }
    } else if(wiz->walkable(new_pos)){
        owner->pos.y += dy;
        owner->pos.x += dx;
    }
}

#include <plurn.h>

void Mover::tryMove(Actor* owner, WorldWiz* wiz, Position pos){
    Position new_pos = {owner->pos.y + pos.y, owner->pos.x + pos.x};

    Actor* obstacle = wiz->actorAt(new_pos);

    if(obstacle && obstacle->blocks){
        if(owner->attacker && obstacle->destructible && owner->name != obstacle->name){
            owner->attacker->attack(owner, obstacle);
        }
    } else if(wiz->walkable(new_pos)){
        owner->pos.y += pos.y;
        owner->pos.x += pos.x;
    }
}

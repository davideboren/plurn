#include <plurn.h>
#include <fmt/core.h>

void Mover::tryMove(Actor* owner, WorldWiz* wiz, Position pos){
    if(!owner->destructible->isDead()){
        Position new_pos = {owner->pos.y + pos.y, owner->pos.x + pos.x};

        Actor* obstacle = nullptr;
        for(Actor* actor : wiz->actorsAt(new_pos)){
           if(actor->blocks){
               obstacle = actor;
           }
        }

        if(obstacle && obstacle->blocks){
            if(owner->attacker && obstacle->destructible && owner->name != obstacle->name){
                owner->attacker->attack(owner, obstacle);
            }
        } else if(wiz->walkable(new_pos)){
            owner->pos.y += pos.y;
            owner->pos.x += pos.x;
        }
    }
}


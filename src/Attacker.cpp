#include <plurn.h>

void Attacker::attack(Actor* owner, Actor* target){
    if(target->destructible && !target->destructible->isDead()){
        target->destructible->takeDamage(target, rng::rand(1,power));
    }
}

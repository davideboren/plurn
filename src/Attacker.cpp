#include <plurn.h>
#include <fmt/core.h>

void Attacker::attack(Actor* owner, Actor* target){
    if(target->destructible && !target->destructible->isDead()){
        wiz->feed->append_buffer(fmt::format("{} attacks {}!", owner->name, target->name));
        std::string live_name = target->name;
        target->destructible->takeDamage(target, rng::rand(1,power));
        if(target->destructible->isDead()){
            wiz->feed->append_buffer(fmt::format("{} has killed {}.", owner->name, live_name));
        }
        if(target->attacker){
            target->attacker->target = owner;
        }
    }
}

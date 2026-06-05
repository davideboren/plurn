#ifndef DESTRUCTIBLE_H
#define DESTRUCTIBLE_H

#include <plurn.h>

class Destructible {
    public:
        int hp;
        int max_hp;

        std::string corpse_name;

        Destructible(int hp, int max_hp, std::string corpse_name) : 
            hp(hp),
            max_hp(max_hp),
            corpse_name(corpse_name) {};

        void takeDamage(Actor* owner, int damage);
        void die(Actor* owner);
        inline bool isDead() { return hp <= 0; };
};

#endif

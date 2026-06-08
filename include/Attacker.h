#ifndef ATTACKER_H
#define ATTACKER_H

#include <plurn.h>

class Attacker {
    public:
        int power;
        Actor* target;

        Attacker(int power) : power(power), target(nullptr){};

        void attack(Actor* owner, Actor* target);
};

#endif

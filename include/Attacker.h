#ifndef ATTACKER_H
#define ATTACKER_H

#include <plurn.h>

class Attacker {
    public:
        int power;
        Attacker(int power) : power(power){};

        void attack(Actor* owner, Actor* target);
};

#endif

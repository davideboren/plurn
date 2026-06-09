#ifndef ATTACKER_H
#define ATTACKER_H

#include <plurn.h>
#include <WorldWiz.h>

class Attacker {
    public:
        WorldWiz* wiz;

        int power;
        Actor* target;

        Attacker(WorldWiz* wiz, int power) : wiz(wiz), power(power), target(nullptr){};

        void attack(Actor* owner, Actor* target);
};

#endif

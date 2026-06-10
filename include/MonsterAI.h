#ifndef MONSTERAI_H
#define MONSTERAI_H

#include <AI.h>

class MonsterAI : public AI{
    public:
        using AI::AI;

        void handleInput(Actor* owner, int input);
        void update(Actor* owner);
};

#endif

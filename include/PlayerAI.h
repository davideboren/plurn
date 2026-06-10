#ifndef PLAYERAI_H
#define PLAYERAI_H

#include <AI.h>

class PlayerAI : public AI {

    public:
        void handleInput(Actor* owner, int input);
};

#endif

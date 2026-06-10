#ifndef AI_H
#define AI_H

#include <structs.h>

#include <Action.h>
#include <Actor.h>

class AI {
    public:
        Action cur_action;

        AI() : cur_action(Action::WAIT){};

        virtual void handleInput(Actor* owner, int input) = 0;
        void update(Actor* owner);
        void tryAction(Actor* owner, Actor* target, Action* action);
        void setMove(Actor* owner, int dy, int dx);
};

#endif

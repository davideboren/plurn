#ifndef AI_H
#define AI_H

#include <structs.h>

#include <Action.h>
#include <Actor.h>
#include <WorldWiz.h>

class AI {
    public:
        Action cur_action;
        WorldWiz* wiz;

        AI() : cur_action(Action::WAIT){};
        AI(WorldWiz* wiz) : cur_action(Action::WAIT), wiz(wiz){};

        virtual void handleInput(Actor* owner, int input) = 0;
        virtual void update(Actor* owner) = 0;
        void tryAction(Actor* owner);
        void setMove(Actor* owner, int dy, int dx);
};

#endif

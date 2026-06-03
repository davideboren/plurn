#ifndef ENTITY_H
#define ENTITY_H

#include <Action.h>
#include <structs.h>

class Actor {

    public:
        Actor();
        Position pos;
        bool visible;
        int ch;
        int color;

        int hp;

        Action cur_action;

        void update();
        Action getAction();
        void setAction(Action action);
};

#endif

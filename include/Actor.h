#ifndef ENTITY_H
#define ENTITY_H

#include <plurn.h>

class Actor {

    public:

        //Components
        Destructible* destructible;
        Attacker* attacker;

        std::string name;
        Position pos;
        bool alive;
        bool visible;
        bool blocks;
        int ch;
        int color;

        Actor* target;

        Action cur_action;

        Actor();
        virtual void update();
        Action getAction();
        void setAction(Action action);
};

#endif

#ifndef ENTITY_H
#define ENTITY_H

#include <Action.h>
#include <structs.h>

#include <string>
class Actor {

    public:
        struct stats {
            int max_hp;
            int cur_hp;
            int atk;
        };

        std::string name;
        Actor::stats stats;
        Position pos;
        bool alive;
        bool visible;
        bool blocks;
        int ch;
        int color;

        Actor* target;

        Action cur_action;

        Actor();
        void update();
        Action getAction();
        void setAction(Action action);
        void die();
};

#endif

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
            int ac;
        };

        std::string name;
        Actor::stats stats;
        Position pos;
        bool alive;
        bool visible;
        bool blocks;
        int ch;
        int color;

        Action cur_action;

        Actor() : name("a creature"),alive(true),blocks(true){};
        void update();
        Action getAction();
        void setAction(Action action);
        void die();
};

#endif

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
        };

        std::string name;
        Position pos;
        bool visible;
        int ch;
        int color;

        Action cur_action;

        Actor();
        void update();
        Action getAction();
        void setAction(Action action);
};

#endif

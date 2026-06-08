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

        Map* map;
        std::vector<Actor*>* actors;

        Actor* target;

        Action cur_action;

        Actor();
        Actor(Map* map, std::vector<Actor*>* actors) :
            map(map), actors(actors){};

        virtual void update();
        Action getAction();
        void setAction(Action action);
};

#endif

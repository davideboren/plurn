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
        bool visible;
        bool blocks;
        int ch;
        int color;

        Map* map;
        std::vector<Actor*>* actors;

        Action cur_action;

        Actor() :
            destructible(nullptr),
            attacker(nullptr),
            name("a creature"),
            blocks(true){};

        Actor(Map* map, std::vector<Actor*>* actors) :
            destructible(nullptr),
            attacker(nullptr),
            name("a creature"),
            blocks(true),
            map(map), actors(actors){};

        virtual void update();
        Action getAction();
        void setAction(Action action);
};

#endif

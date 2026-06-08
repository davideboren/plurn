#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

#include <structs.h>

#include <Map.h>
#include <Action.h>

#include <Destructible.h>
#include <Attacker.h>
#include <Mover.h>

#include <WorldWiz.h>

class Actor {

    public:

        //Components
        Destructible* destructible;
        Attacker* attacker;
        Mover* mover;

        std::string name;
        Position pos;
        bool visible;
        bool blocks;
        int ch;
        int color;

        WorldWiz* wiz;

        Action cur_action;

        Actor() :
            destructible(nullptr),
            attacker(nullptr),
            mover(nullptr),
            name("a creature"),
            blocks(true){};

        Actor(WorldWiz* wwiz) :
            destructible(nullptr),
            attacker(nullptr),
            mover(nullptr),
            name("a creature"),
            blocks(true),
            wiz(wwiz){};

        virtual void update();
        Action getAction();
        void setAction(Action action);
};

#endif

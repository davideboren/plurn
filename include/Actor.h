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
class AI;
#include <AI.h>
class Inventory;
#include <Inventory.h>

#include <WorldWiz.h>

class Actor {

    public:

        //Components
        Destructible* destructible;
        Attacker* attacker;
        Mover* mover;
        AI* ai;
        Inventory* inventory;

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
            ai(nullptr),
            inventory(nullptr),
            name("a creature"),
            blocks(true){};

        Actor(WorldWiz* wwiz) :
            destructible(nullptr),
            attacker(nullptr),
            mover(nullptr),
            ai(nullptr),
            inventory(nullptr),
            name("a creature"),
            visible(false),
            blocks(true),
            wiz(wwiz){};
};

#endif

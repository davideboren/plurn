#ifndef INVENTORY_H
#define INVENTORY_H

#include <plurn.h>
#include <WorldWiz.h>
#include <vector>

class Inventory {
    public:
        WorldWiz* wiz;

        std::vector<Actor*> contents;

        Inventory(WorldWiz* wiz): wiz(wiz){};

        void pickUp(Actor* owner, Position pos);
};

#endif

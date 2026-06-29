#ifndef MOVER_H
#define MOVER_H

#include <plurn.h>
#include <WorldWiz.h>

class Mover {
    public:
        int dy;
        int dx;

        Mover() : dy(0), dx(0){};

        void tryMove(Actor* owner, WorldWiz* wiz, Position pos);
};
#endif

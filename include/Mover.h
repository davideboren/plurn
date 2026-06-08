#ifndef MOVER_H
#define MOVER_H

#include <plurn.h>
#include <WorldWiz.h>

class Mover {
    public:
        Map* map;
        std::vector<Actor*>* actors;

        int dy;
        int dx;

        Mover(Map* map, std::vector<Actor*>* actors) : 
            map(map), actors(actors),
            dy(0), dx(0){};

        void tryMove(Actor* owner, WorldWiz* wiz);
};
#endif

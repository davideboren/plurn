#ifndef ENTITY_H
#define ENTITY_H

#include <Action.h>
#include <structs.h>

class Actor {

    public:
        Position pos;
        bool visible;
        int ch;
        int color;

        Action update();
};

#endif

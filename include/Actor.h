#ifndef ENTITY_H
#define ENTITY_H

#include <structs.h>

class Actor {

    public:
        virtual ~Actor() = default;
        Position pos;
        bool visible;
        int ch;
        int color;

        virtual void update();
};

#endif

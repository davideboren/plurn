#ifndef ENTITY_H
#define ENTITY_H

#include <structs.h>

class Entity {

    public:
        virtual ~Entity() = default;
        Position pos;
        bool visible;
        int ch;
        int color;

        void update();
};

#endif

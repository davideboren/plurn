#ifndef ACTION_H
#define ACTION_H

#include <vector>
class Actor;

class Action {

    public:
        enum Type {
            WAIT,
            MOVE,
            ATTACK,
            PICK_UP
        };

        Type type;

        // Movement
        int dy, dx;

        // Inventory
        std::vector<Actor*> pickup_targets;

        Action() :
            type(Action::WAIT),
            dy(0),
            dx(0)
            {};

        Action(Type t) :
            type(t),
            dy(0),
            dx(0)
            {};

};
#endif

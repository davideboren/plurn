#ifndef ACTION_H
#define ACTION_H

class Action {

    public:
        enum Type {
            WAIT,
            MOVE
        };

        Action(Type t) : type(t){};
        Type type;

        int dy, dx;
};
#endif

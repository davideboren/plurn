#ifndef PLAYER_H
#define PLAYER_H

#include <Actor.h>

class Player : public Actor{
    public:
        void initPlayer();
        void update();
        void setMove(int dy, int dx);
};

#endif

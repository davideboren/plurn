#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>

class Player : public Entity{
    public:
        Player();
        void initPlayer(int y, int x);
        void handleInput(int input);
};

#endif

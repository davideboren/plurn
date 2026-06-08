#ifndef PLAYER_H
#define PLAYER_H

#include <plurn.h>

class Player : public Actor{
    public:
        void initPlayer(WorldWiz* wiz, Map* map, std::vector<Actor*>* actors);
        void update();
        void setMove(int dy, int dx);
};

#endif

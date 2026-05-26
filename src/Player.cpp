#include <Entity.h>
#include <Player.h>

Player::Player(){
   ch = '@';
}

void Player::initPlayer(int y, int x){
    pos.y = y;
    pos.x = x;
}


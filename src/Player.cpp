#include <Entity.h>
#include <Player.h>

Player::Player(){
   ch = '@';
}

void Player::initPlayer(int y, int x){
    pos.y = y;
    pos.x = x;
}

void Player::handleInput(int input){
    switch(input){
    case 'h':
        pos.x--;
        break;
    case 'j':
        pos.y++;
        break;
    case 'k':
        pos.y--;
        break;
    case 'l':
        pos.x++;
        break;
    }
}

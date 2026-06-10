#include <PlayerAI.h>

void PlayerAI::handleInput(Actor* owner, int input){
    if(!owner->destructible->isDead()){
        switch(input){
            // Movement
            case KEY_LEFT:
            case 'h':
                setMove(owner, 0, -1); 
                break;
            case KEY_DOWN:
            case 'j':
                setMove(owner, 1, 0); 
                break;
            case KEY_UP:
            case 'k':
                setMove(owner, -1, 0); 
                break;
            case KEY_RIGHT:
            case 'l':
                setMove(owner, 0, 1); 
                break;
            case 'b':
                setMove(owner, 1, -1); 
                break;
            case 'u':
                setMove(owner, -1, 1); 
                break;
            case 'n':
                setMove(owner, 1, 1); 
                break;
            case 'y':
                setMove(owner, -1, -1); 
                break;
            case '.':
                cur_action = Action::WAIT;
                break;
            default:
                break;
        }
    }
}

void PlayerAI::update(Actor* owner){

}

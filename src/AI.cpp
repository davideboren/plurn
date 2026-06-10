#include <AI.h>

void AI::setMove(Actor* owner, int dy, int dx){
    owner->cur_action.type = Action::MOVE;
    owner->cur_action.dy = dy;
    owner->cur_action.dx = dx;
}

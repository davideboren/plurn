#include <Monster.h>

#include <structs.h>
#include <rng.h>

Position Monster::randomMove(){ 
    Position pos;

    pos.y = rng::rand(-1, 1);
    pos.x = rng::rand(-1, 1);

    return pos;
}

void Monster::update(){
    
}

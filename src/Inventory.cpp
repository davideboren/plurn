#include <Inventory.h>
#include <Logger.h>

void Inventory::pickUp(Actor* owner, Position pos){
    for(Actor* actor : wiz->actorsAt(pos)){
        if(actor != owner && actor->collectible){
            contents.push_back(actor);
            actor->pos = {-1, -1};
        }
    }
    for(Actor* actor : contents){
        Logger::log(fmt::format("Inv: {}.", actor->name));
    }
}

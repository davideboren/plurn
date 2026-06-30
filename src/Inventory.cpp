#include <Inventory.h>
#include <Logger.h>

void Inventory::pickUp(Actor* owner, Position pos){
    for(Actor* actor : wiz->actorsAt(pos)){
        if(actor != owner && actor->collectible){
            contents.push_back(actor);
            actor->pos = {-1, -1};
            wiz->feed->append_buffer(fmt::format("Grabbed {}.", actor->name));
        }
    }
}

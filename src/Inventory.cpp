#include <Inventory.h>
#include <Logger.h>

void Inventory::pickUp(Position pos){
    for(Actor* actor : wiz->actorsAt(pos)){
        Logger::log(fmt::format("On top of {}", actor->name));
    }
}

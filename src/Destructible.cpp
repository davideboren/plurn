#include <plurn.h>

void Destructible::takeDamage(Actor* owner, int damage){
   hp -= damage;
   if(hp <= 0){
       die(owner);
   }
}

void Destructible::die(Actor* owner){
    owner->ch = '%';
    owner->blocks = false;
    owner->name = corpse_name;
}

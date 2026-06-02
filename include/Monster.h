#include <Entity.h>
#include <string>

class Monster : public Entity {
    
    public:
        std::string name;
        Position randomMove(); 
        int hp;
        bool hostile;
};

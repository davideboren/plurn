#include <Actor.h>
#include <string>

class Monster : public Actor {
    
    public:
        std::string name;
        int hp;
        bool hostile;

        Position randomMove();
        void update();

};

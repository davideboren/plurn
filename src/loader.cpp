#include <loader.h>

#include <fstream>
#include <json.hpp>
#include <Logger.h>

#include <MonsterAI.h>

using json = nlohmann::json;

namespace loader{
    Actor* loadActor(const char* filename, const char* actor, WorldWiz* wiz){

        Actor* out_actor = new Actor(wiz);

        try{

            std::ifstream f(filename);
            json jdata = json::parse(f);

            out_actor->name = jdata[actor]["name"];
            std::string ch_str = jdata[actor]["ch"];
            out_actor->ch = static_cast<int>(ch_str[0]);

            if(jdata[actor].contains("destructible")){
                int hp = jdata[actor]["destructible"]["hp"];
                int max_hp = jdata[actor]["destructible"]["max_hp"];
                std::string corpse_name = jdata[actor]["destructible"]["corpse_name"];
                out_actor->destructible= new Destructible(hp, max_hp, corpse_name);
            }
            if(jdata[actor].contains("attacker")){
                int power = jdata[actor]["attacker"]["power"];
                out_actor->attacker = new Attacker(wiz, power);
            }
            if(jdata[actor].contains("mover")){
                out_actor->mover = new Mover();
            }
            out_actor->ai = new MonsterAI(wiz);

            if(jdata[actor].contains("collectible")){
                if(jdata[actor]["collectible"] == true){
                    out_actor->collectible = new Collectible();
                }
            }

        } catch (const std::exception& e){
            Logger::log(fmt::format("{}", e.what()));

            out_actor->name = "Missingno";
            out_actor->ch = '?';
        }
        return out_actor;
    }
}

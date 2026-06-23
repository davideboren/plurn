#include <loader.h>

#include <fstream>
#include <json.hpp>
#include <Logger.h>

using json = nlohmann::json;

namespace loader{
    Actor* loadActor(const char* filename, const char* actor, WorldWiz* wiz){

        Actor* out_actor = new Actor(wiz);

        try{

            std::ifstream f(filename);
            json jdata = json::parse(f);

            out_actor->name = jdata["slimoid"]["name"];
            std::string ch_str = jdata["slimoid"]["ch"];
            out_actor->ch = static_cast<int>(ch_str[0]);

            //out_actor->destructible = 
            //out_actor->attacker = 
            //out_actor->mover = 
            //out_actor->ai = 

        } catch (const std::exception& e){
            Logger::log(fmt::format("{}", e.what()));

            out_actor->name = "Missingno";
            out_actor->ch = '?';
        }
        return out_actor;
    }
}

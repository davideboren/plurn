#include <WorldBuilder.h>

#include <fstream>
#include <json.hpp>

#include <structs.h>
#include <Map.h>
#include <World.h>

using json = nlohmann::json;
World WorldBuilder::buildWorldFromJSONFile(const char* filename){
    World world;

    std::ifstream f(filename);
    json data = json::parse(f); 

    world.map.initMap();

    for(int i = 0; i < data["rooms"].size(); i++){
        Room r = world.map.createRoom(
            data["rooms"][i]["y"],
            data["rooms"][i]["x"],
            data["rooms"][i]["h"],
            data["rooms"][i]["w"]
        );

        world.map.placeRoom(r);
    }

    world.initEntities();

    return world;

}

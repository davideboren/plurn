#include <MapBuilder.h>

#include <fstream>
#include <json.hpp>

#include <structs.h>
#include <Map.h>

using json = nlohmann::json;
Map MapBuilder::buildMapFromJSONFile(const char* filename){
    Map map;

    std::ifstream f(filename);
    json data = json::parse(f); 

    for(int i = 0; i < data["rooms"].size(); i++){
        Room r = map.createRoom(
            data["rooms"][i]["y"],
            data["rooms"][i]["x"],
            data["rooms"][i]["h"],
            data["rooms"][i]["w"]
        );

        map.placeRoom(r);
    }

    return map;

}

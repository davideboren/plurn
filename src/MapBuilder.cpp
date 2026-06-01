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

    Position prev_center = {-1, -1};

    for(int i = 0; i < int(data["rooms"].size()); i++){
        Room r = map.createRoom(
            data["rooms"][i]["y"],
            data["rooms"][i]["x"],
            data["rooms"][i]["h"],
            data["rooms"][i]["w"]
        );

        map.placeRoom(r);

        if(prev_center.y != -1){
            map.connectPoints(prev_center, r.center);
        }

        prev_center = r.center;
    }

    return map;

}

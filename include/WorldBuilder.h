#ifndef WORLDBUILDER_H
#define WORLDBUILDER_H

#include <World.h>
#include <json.hpp>
#include <fstream>

class WorldBuilder {
    public:
        World buildWorldFromJSONFile(const char* filename); 
};

#endif

#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <Map.h>

class MapBuilder {
    public:
        Map buildMapFromJSONFile(const char* filename); 
};

#endif

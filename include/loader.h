#pragma once

#include <Actor.h>

namespace loader{
    Actor* loadActor(const char* filename, const char* actor, WorldWiz* wiz);
}

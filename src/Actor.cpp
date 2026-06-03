#include <Actor.h>

#include <Action.h>
#include <Logger.h>
#include <fmt/core.h>
#include <rng.h>

Action Actor::update(){
    Action action(Action::MOVE);
    action.dy = rng::rand(-1,1);
    action.dx = rng::rand(-1,1);

    return action;
}

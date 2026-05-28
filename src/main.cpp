#include <ncurses.h>
#include <stdio.h>

#include <constants.h>
#include <Engine.h>
#include <Logger.h>

int main(){

    Logger::init("debug.log");

    Engine engine;

    if(!engine.initCurses()){
        endwin();
    }

    engine.initPanels();

    engine.gameLoop();

    endwin();

    return 0;
}

#include <ncurses.h>
#include <stdio.h>

#include <constants.h>
#include <Engine.h>

int main(){

    WINDOW* w_world;

    Engine engine;

    if(!engine.initCurses()){
        endwin();
    }
    engine.initPanels();

    engine.gameLoop();

    endwin();

    return 0;
}

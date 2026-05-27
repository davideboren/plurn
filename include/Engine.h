#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <ncurses.h>
#include <string>

#include <World.h>

class Engine {
    public:
        Engine();
        bool initCurses();
        void initPanels();
        void gameLoop();

    private:
        int handleInput(int input);
        void update();
        void render();

        WINDOW* w_world;
        WINDOW* w_info;
        World world;

};

#endif

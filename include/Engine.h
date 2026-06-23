#ifndef ENGINE_H
#define ENGINE_H

#include <ncurses.h>

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

        WINDOW* w_stats;
        WINDOW* w_world;
        WINDOW* w_dialogue;
        WINDOW* w_info;
        World world;

        static const bool SEE_ALL = false;

};

#endif
